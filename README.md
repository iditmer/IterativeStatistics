# Iterative Statistics
Classes used for computing sample statistics iteratively following a single pass through the data. Alleviates the need to have all relevant observations loaded into the same container, or even in memory, simultaneously. Usage in most cases is of the following form:

```cpp

    UnivariateSample stats{};
    
    for (const auto& observation : collection){
        stats.update(observation);
    }
    
    std::cout << "Average Observation: " << stats.Mean() << "\n";
    std::cout << "Variance in Observations: " << stats.Variance() << "\n";
  
```

#### Common Use Case: Disjoint Storage ####
Often times large data sets are stored in multiple files or multiple locations. If summary statsitics for such data are required it is generally impractical to load all observations into a single container.

```cpp
    UnivariateSample stats{};
    
    for (file : list_of_Files){
        for (const auto& observation : collection){
          stats.update(observation);
        }
    }
```

#### Common Use Case: Subset Statistics ####
When working with larger data sets there is frequently a need for sample statistics computed from subsets of the observations. Generally this requires that the subset be comprised of observations meeting specific criteria.


```cpp
    UnivariateSample stats{};
    
    for (const auto& observation : collection){
        if (observation meets criteria){
          stats.update(observation);
        }
    }
```

