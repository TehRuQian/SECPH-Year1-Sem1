# Number of data
n = 500

# Hypothesis Testing One Sample
hypothesisTesting = function(data, mu, alpha){
  xbar = mean(data)
  s = sd(data)
  
  # Test statistics
  t = (xbar-mu)/(s/sqrt(n))
  
  # Critical Value
  t.alpha = qt(p=alpha, df=n-1, lower.tail=FALSE)
  
  # P-value
  pval = pt(t, df=n-1, lower.tail=FALSE)
  
  # Print statistics
  print(paste("Sample mean: ", xbar))
  print(paste("Sample Standard Deviation: ", s))
  print(paste("Test statistics: ", t))
  print(paste("Critical value: ", t.alpha))
  print(paste("P-value: ", pval))
}

# Correlation Testing
correlationTesting = function(data1, data2, xlbl, ylbl, alpha){
  
  #calculate correlation
  r = cor(data1, data2)
  
  #plot graph
  plot(data1, data2, xlim = c(0,100), ylim = c(0,100), xlab = xlbl, ylab = ylbl )
  
  #calculate test statistics
  t0 = r/(sqrt((1-r^2)/(n-2)))
  
  #calculate degree of freedom
  v = n-2
  
  #calculate critical value
  t.alpha = qt(1-alpha/2, floor(n-2))
  
  #print values
  print(paste("Correlation =", r))
  print(paste("t-statistic =", t0))
  print(paste("Degrees of freedom =", v))
  print(paste("Critical value at alpha", alpha, "=", t.alpha))
}

# Regression
# Function to calculate t-value (for regression)
calculate_t_value <- function(coeff_estimate, std_error) {
  t_value <- coeff_estimate / std_error
  return(t_value)
}

# Function to calculate critical t-value (for regression)
calculate_critical_t_value <- function(alpha, df) {
  critical_t_value <- qt(1 - alpha/2, df = df)  # Two-tailed test
  return(critical_t_value)
}

# Regression Test function
regressionTesting <- function(dependent_var_name, independent_var_name, dependent_label, independent_label, plot_title, alpha = 0.05) {
  x <- ranking[[independent_var_name]]
  y <- ranking[[dependent_var_name]]
  
  if (length(x) > 0 && length(y) > 0) {
    model <- lm(y ~ x)
    summary_model <- summary(model)
    
    print(paste("Regression:", dependent_label, "vs", independent_label))
    print(summary_model)
    
    plot(x, y, main = plot_title, xlab = independent_label, ylab = dependent_label, xlim = c(0, 100), ylim = c(0, 100))
    abline(model, col = "blue")
    
    b1 <- summary_model$coefficients[2, "Estimate"]
    sb1 <- summary_model$coefficients[2, "Std. Error"]
    df <- summary_model$df[2]
    
    t_value <- calculate_t_value(b1, sb1)
    
    print("T-test Results:")
    print(paste("Test statistic (t):", sprintf("%.3f", t_value)))
    print(paste("Degrees of freedom:", sprintf("%d", df)))
    
    critical_t <- calculate_critical_t_value(alpha, df)
    print(paste("Critical t-value (alpha =", alpha, "):", format(critical_t, nsmall = 10)))
  } else {
    cat("Error: No valid data points for regression.\n")
  }
}

# Get Data
academicReputation = ranking$`Academic Reputation`
overallScore = ranking$`QS Overall Score`
employerReputation = ranking$`Employer Reputation`

# <<<<< Hypothesis Testing One Sample >>>>>
# Academic Reputation
hypothesisTesting(academicReputation, 40, 0.05)

# Employer Reputation
hypothesisTesting(employerReputation, 40, 0.05)

# QS Overall Score
hypothesisTesting(overallScore, 40, 0.05)

# <<<<< Corelation >>>>>
# Correlation between Academic Reputation and Employer Reputation
correlationTesting(academicReputation, employerReputation, "Academic Reputation", "Employer Reputation", 0.05)

# Correlation between Academic Reputation and QSoverallScore
correlationTesting(academicReputation, overallScore, "Academic Reputation", "QS Overall Score", 0.05)

# Correlation between Employer Reputation and QSoverallScore
correlationTesting(employerReputation, overallScore, "Employer Reputation", "QS Overall Score", 0.05)

# <<<<< Regression >>>>>
# Perform regression tests and plot for each pair
par(mfrow = c(1, 3))

# 3.3.1 Academic Reputation vs Employer Reputation
print("3.3.1 Academic Reputation vs Employer Reputation")
regressionTesting("Employer Reputation", "Academic Reputation", "Employer Reputation", "Academic Reputation", "Academic Reputation vs Employer Reputation")

# 3.3.2 Academic Reputation vs QS Overall Score
print("3.3.2 Academic Reputation vs QS Overall Score")
regressionTesting("Academic Reputation", "QS Overall Score", "Academic Reputation", "QS Overall Score", "Academic Reputation vs QS Overall Score")

# 3.3.3 Employer Reputation vs QS Overall Score
print("3.3.3 Employer Reputation vs QS Overall Score")
regressionTesting("Employer Reputation", "QS Overall Score", "Employer Reputation", "QS Overall Score", "Employer Reputation vs QS Overall Score")


# <<<<< Goodness of Fit Test >>>>>
#calculate observed frequencies for the 'location' column
noSize <- table(ranking$Size)

#Define expected frequencies (equal probability)
expprob <- rep(sum(noSize)/length(noSize), length(noSize))
expprob

#Perform the chi-square goodness of fit test
output <- chisq.test(noSize, p = expprob/sum(expprob), correct = FALSE)

#print table of size(observation)
print(noSize)

#Calculate Critical Value
alpha <- 0.05
degrees_of_freedom <- output$parameter
critical_value <- qchisq(alpha, df = degrees_of_freedom, lower.tail = FALSE)

goodnessOfFitTest <- function(degrees_of_freedom, critical_value, output){
  print(paste("Degree Of Freedom:", degrees_of_freedom))
  print(paste("Critical Value:", critical_value))
  print(output)
}

goodnessOfFitTest(degrees_of_freedom, critical_value, output)

