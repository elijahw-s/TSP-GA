/*
 * Declarations for Deme class to evolve a genetic algorithm for the
 * travelling-salesperson problem.  A deme is a population of individuals.
 */

#include "chromosome.hh"
#include "deme.hh"

// Generate a Deme of the specified size with all-random chromosomes.
// Also receives a mutation rate in the range [0-1].
Deme::Deme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
{
  for (unsigned i=0; i<pop_size; i++){


  }
  double mut_rate_ = mut_rate;
}

// Clean up as necessary
Deme::~Deme()
{
  // Add your implementation here
}

// Evolve a single generation of new chromosomes, as follows:
// We select pop_size/2 pairs of chromosomes (using the select() method below).
// Each chromosome in the pair can be randomly selected for mutation, with
// probability mut_rate, in which case it calls the chromosome mutate() method.
// Then, the pair is recombined once (using the recombine() method) to generate
// a new pair of chromosomes, which are stored in the Deme.
// After we've generated pop_size new chromosomes, we delete all the old ones.
void Deme::compute_next_generation()
{
  std::vector<Chromosome*> new_pop_;
  for (int i=0; i<pop_size/2; i++){
    auto chrom1 = select_parent();
    auto chrom2 = select_parent();
    auto new_chroms = chrom1.recombine(*chrom2);
    new_pop_.push_back(new_chroms.first);
    new_pop_.push_back(new_chroms.second);
  }
  pop_ = new_pop_;
}

// Return a copy of the chromosome with the highest fitness.
const Chromosome* Deme::get_best() const
{
  double best = 0;
  double fitness;
  auto best_chrom;
  for (auto chrom : pop_){
    fitness = chrom.get_fitness();
    if (fitness > best){
      best = fitness;
      best_chrom = chrom;
    }
  }
  return best_chrom->clone();
}

// Randomly select a chromosome in the population based on fitness and
// return a pointer to that chromosome.
Chromosome* Deme::select_parent()
{
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 gen(rd()); // seed the generator
  
	//define the range as [0, len)
	std::uniform_real_distribution<> dist1(0, 1); 
  double total_prob = 0
  double total_fitness = 0;
  for (auto chrom : pop_){
    total_fitness += chrom.get_fitness();
  }
  double prob = dist1(gen);
  for (auto chrom : pop_){
    total_prob += (chrom.get_fitness()/total_fitness);
    if (total_prob > prob){
      return chrom*;
    }
  }
}
