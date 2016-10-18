#ifndef INPUT_H
#define INPUT_H

/*

This file is part of VROOM.

Copyright (c) 2015-2016, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include <array>
#include <vector>
#include <boost/optional.hpp>
#include "../typedefs.h"
#include "../abstract/matrix.h"
#include "./job.h"
#include "./vehicle.h"
#include "../../utils/exceptions.h"
#include "../../routing/routing_io.h"

class input{
private:
  index_t _location_number;
  void set_matrix();

protected:
  std::vector<job> _jobs;
  std::vector<vehicle> _vehicles;
  matrix<distance_t> _matrix;
  std::unique_ptr<routing_io<distance_t>> _routing_wrapper;
  // List of locations added through add_* matching the matrix
  // ordering.
  std::vector<std::reference_wrapper<location>> _ordered_locations;

public:
  input();

  void add_job(index_t id, optional_coords_t coords);

  void add_vehicle(index_t id,
                   optional_coords_t start_coords,
                   optional_coords_t end_coords);

  index_t get_location_number();

  friend input parse(const std::string& input_string);
};

#endif
