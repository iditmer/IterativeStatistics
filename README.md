# Iterative Statistics
Classes used for computing sample statistics from observations without requiring all data to be loaded into memory concurrently. The most common use case is reporting statistics from very large data sets, possibly stored in multiple files or locations. 

```cpp

    UnivariateSample stats{};
    
    for (auto observation : collection){
      // evaluate conditions, perform other processing, etc.
      stats.update(observation);
    }
    
    std::cout << "Average Observation: " << stats.Mean() << "\n";
    std::cout << "Variance in Observations: " << stats.Variance() << "\n";
  
```
