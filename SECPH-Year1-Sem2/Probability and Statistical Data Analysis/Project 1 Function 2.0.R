# Rename the excel file to "Responses" and import

# Import libraries
library(moments)
library(plotrix)
library(lessR)
library(RColorBrewer)
library(ggplot2)

# Function
quantitative = function(data, title){
  print(paste("Mean: ", mean(data)))
  print(paste("Median: ", median(data)))
  
  unique.value <- unique(data)
  unique.match <- match(data, unique.value)
  unique.freq <- tabulate(unique.match)
  unique.max <- which.max(unique.freq)
  data.mode <- unique.value[unique.max]
  print(paste("Mode: ", data.mode))
  
  print("Quartile: ")
  print(quantile(data, type=2))
  
  boxplot(data,
          ylab = title, 
          main = paste(title, "Distribution"),
          col = "lightblue")
  
  print(paste("Variance: ", var(data)))
  print(paste("Standard deviation: ", sd(data)))
  print(paste("Skewness: ", skewness(data)))
  print(paste("Kurtosis: ", kurtosis(data)))
  
  # Histogram
  hist(data, 
       main = paste(title, "Distribution"), 
       col = "lightblue",
       xlab = title)
  
  # Ogive
  interval = (max(data) - min(data)) / (1 + 3.322 * log(length(data), base=10))
  data.breaks = seq(min(data), max(data), interval)
  data.cut = cut(data, data.breaks)
  data.freq = table(data.cut)
  data.cs = c(0, cumsum(data.freq))
  plot(data.breaks, data.cs, 
       xlab = title, 
       ylab = "Cummulative Frequency",
       main = title, 
       type='b', pch=19, bty='l')
  # lines(data.breaks, data.cs)
}

# Categerical Data
qualitative = function(data, title){
  data.freq = table(data)
  data.freq = data.freq[order(-data.freq)]
  print(data.freq)
  
  data.rfq = data.freq/sum(data.freq)
  print(data.rfq)
  
  # Barplot
  barplot(data.freq,
          col = "lightblue",
          ylab = "Frequency",
          main = title)
  
  # Pie Chart
  # colors <- brewer.pal(n = length(data.freq), name = "Pastel1")
  pie_labels <- paste0(round(100 * data.freq/sum(data.freq), 2), "%")
  scale <- unique(data)
  ggplot(data = as.data.frame(data.freq), aes(x = "", y = Freq, fill = factor(names(data.freq)))) +
    geom_col(color = "black") +
    geom_text(aes(label = pie_labels), position = position_stack(vjust = 0.5)) +
    coord_polar(theta = "y", start = 1) +
    labs(title = title) +
    theme_void() +
    guides(fill = guide_legend(title = NULL)) +
    theme(legend.position = "right", plot.title = element_text(hjust = 0.5, face = "bold")) +
    scale_fill_brewer(breaks = scale, name = NULL)
    # scale_fill_manual(values = colors, breaks = scale, labels = scale)
}

# Ordinal
ordinal = function(data, title){
  print(title)
  
  # Convert data to factor with specified levels
  data <- factor(data, levels = 1:5)
  # Tabulate the data
  data.freq = table(data)
  print(data.freq)
  data.rfq = data.freq/sum(data.freq)
  print(data.rfq)
  
  scale = c("Strongly\nDisagree",
            "Disagree",
            "Neutral",
            "Agree",
            "Strongly\nAgree")
  
  barplot(data.freq,
          col = "lightblue",
          ylab = "Frequency",
          main = title,
          names.arg = scale)
  
  pie_labels <- paste0(round(100 * data.freq/sum(data.freq), 3), "%")
  
  pie(data.freq, clockwise = TRUE, labels = pie_labels, main = title)
  #legend("right", legend = scale, fill =  c("white", "lightblue", "mistyrose", "lightcyan", "lavender"))
  
}

# 1. Age (Ratio)
age = Responses$Age
quantitative(age, "Age")
qualitative(age, "Age")

# 2. Gender (Nominal)
gender = Responses$Gender
qualitative(gender, "Gender")

# 3. Ethnicity (Nominal)
ethnicity = Responses$Ethnicity
qualitative(ethnicity, "Ethnicity")

# 4. Year of Study (Ordinal)
year = Responses$`Year of Study`
qualitative(year, "Year of Study")

# 5. Faculty (Nominal)
faculty = Responses$Faculty
qualitative(faculty, "Faculty")

# 6. Allowance Received From Parents (Nominal)
allowance = Responses$`Allowance received from parents per month`
quantitative(allowance, "Monthly Allowance\nReceived from Parents")

# 7. Part time job & Salary
job = Responses$`Do you have a part time job?`
qualitative(job, "Part Time Job")

salary = Responses$`If yes, please state your salary per month.`
salary = na.omit(salary)
quantitative(salary, "Part Time Job Monthly Salary")

# 8. Financial Aid
aid = Responses$`Do you have a scholarship or student loan?`
qualitative(aid, "Financial Aid")

aidAllowance = Responses$`If yes, how much per semester?`
aidAllowance = na.omit(aidAllowance)
quantitative(aidAllowance, "Allowance per Semester")

# 9. Total Expenses (Ratio)
expenses = Responses$Total
quantitative(expenses, "Total Expenses")

# 10. Food (Ratio)
food = Responses$`For Food`
quantitative(food, "Monthly Expenses on Food")

# 11. Entertainment (Ratio)
entertainment = Responses$`For Entertainment`
quantitative(entertainment, "Monthly Expenses on Entertainment")

# 12. Transportation (Ratio)
transportation = Responses$`For Transportation`
quantitative(transportation, "Monthly Expenses on Transportation")

# 13. Groceries (Ratio)
groceries = Responses$`For Groceries and Health Care Products`
quantitative(groceries, "Monthly Expenses on Groceries and\nHealthcare Products")

# 14. Other expenses (Ratio)
others = Responses$`Other Expenses`
quantitative(others, "Other Monthly Expenses ")

# Boxplot of the expenditure
data <- data.frame(food, entertainment, transportation, groceries, others)
boxplot(data, col = "lightblue", main = "Monthly Expenditure")

# 15. Enough money? (Nominal)
qualitative(Responses$`Is your money enough for your monthly expenses?`, "Are the students' money enough?")

# 16. Need more money? (Nominal)
qualitative(Responses$`Do you need more per month?`, "Do the students need more money?")

# 17. How much is enough? (Ratio)
quantitative(Responses$`How much per month do you think is enough a student studying in UTM ?`, "Ideal Monthly Expenses\nat UTM")

# 18. Monthly saving plan? (Nominal)
qualitative(Responses$`Do you have a monthly savings plan?`, "Monthly Savings Plan Availability")

# 19. Saving per month (Ratio)
quantitative(na.omit(Responses$`If yes, how much do you save monthly?`), "Monthly Savings Amount of Students\nwith Savings Plans")

# Ordinal Datas
colNames = colnames(Responses)
for(x in 24:35){
  ordinal(Responses[[colNames[x]]], colNames[x])
}

colNames


