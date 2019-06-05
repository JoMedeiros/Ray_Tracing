/**
 * @file	sampler.h
 * @author	Josivan Medeiros
 * @version	1
 * @date
 * 	Created: 12 may 2019
 *  Last Update: 30 mai 2019 (08:07:41)
 */
#ifndef SAMPLER_H
#define SAMPLER_H

class Sampler {
  private:
    unsigned samples;
  public:
    Sampler(unsigned s): samples{s}{};
    unsigned get_samples(){ return samples; }
};

#endif // SAMPLER_H

