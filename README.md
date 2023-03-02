# Iterative Statistics
Classes used for computing sample statistics without requiring all observations to be accessible or in memory at once. Key variables are tracked and updated as new observations are seen, allowing statistics to be computed and used at any point after data has been read or accessed. 

As an example, consider the formula for the sample mean:

$$\bar{x} = \frac{1}{n}\sum_{i=1}^n x_i$$

While often computed using an array or container of values, all that is required is the number of observations $n$ and the sum $\sum x_i$. Those two variables may be easily stored and added to at any point, with an updated mean value being one division away. 

We can similarly determine the variables needed for computing variance from its formula:

$$\sigma^2=\frac{1}{n-1}\sum_{i=1}^n \left(x_i - \bar{x}\right)^2$$

$$=\frac{1}{n-1}\sum_{i=1}^n \left({x_i}^2 - 2x_i\bar{x} + \bar{x}^2 \right)$$

$$=\frac{1}{n-1} \left( \sum_{i=1}^n {x_i}^2 - 2\bar{x}\sum_{i=1}^n x_i + \sum_{i=1}^n \bar{x}^2 \right)$$

$$=\frac{1}{n-1} \left( \sum_{i=1}^n {x_i}^2 - 2\left(\frac{1}{n}\sum_{i=1}^n x_i\right)\left(\sum_{i=1}^n x_i\right) + n\bar{x}^2 \right)$$

$$=\frac{1}{n-1} \left( \sum_{i=1}^n {x_i}^2 - \frac{2}{n}\left(\sum_{i=1}^n x_i\right)^2 + n\left(\frac{1}{n}\sum_{i=1}^n x_i\right)^2 \right)$$

$$=\frac{1}{n-1} \left( \sum_{i=1}^n {x_i}^2 - \frac{1}{n}\left(\sum_{i=1}^n x_i\right)^2 \right)$$

If we are already keeping track of $n$ and $\sum x_i$ iteratively to report the mean, then the inclusion of a third variable to track the value of $\sum x_i^2$ is all that is required to also report the variance (and subsequently, the standard deviation).
