//
//  fld.h
//  expressionline
//
//  Created by Adam Roberts on 3/20/11.
//  Copyright 2011 Adam Roberts. All rights reserved.
//

#ifndef FLD_H
#define FLD_H

#include <vector>

class FLD
{
    /**
     * a private vector that stores the observed counts by length
     */
    std::vector<double> _hist;
    
    /**
     * a private double that stores the total observed counts
     */
    double _tot_mass;
    
    /**
     * a private double that stores the sum of the observations for quick mean calculations
     */
    double _sum;
    
    /**
     * a private int that stores the minimum observed length
     */
    size_t _min;
    
public:
    /**
     * FLD Constructor
     * @param alpha double that sets the average pseudo-counts
     * @param max_val an integer that sets the maximum allowable FragMap length
     * @param mean a size_t for the mean of the prior gaussian dist
     * @param std_dev a size_t for the std dev of the prior gaussian dist
     */
    FLD(double alpha, size_t max_val, size_t mean, size_t std_dev);
    
    /**
     * a member function that returns the maximum allowed FragMap length
     * @return max allowed FragMap length
     */ 
    size_t max_val() const;
    
    /**
     * a member function that returns the mean FragMap length
     * @return mean observed FragMap length
     */ 
    double mean() const;
    
    /**
     * a member function that updates the distribution based on a new FragMap observation
     * @param length an integer for the observed FragMap length
     * @param mass a double for the mass of the observed FragMap
     */
    void add_val(size_t len, double mass);
    
    /**
     * a member function that returns the probability of a given FragMap length
     * @param length an integer for the FragMap length to return the probability of
     * @return probability of observing the given FragMap length
     */ 
    double pdf(size_t len) const;
    
    /**
     * a member function that returns the number of observed fragmaps (including pseudo-counts)
     * @return number of observed fragments
     */ 
    double tot_mass() const;
    
    std::string to_string() const;

};

#endif