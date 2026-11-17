//
// Created by Cocks Kardeiz on 24/09/2026.
//
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>


boost::uuids::random_generator gen;
boost::uuids::uuid uuid = gen();

#include "Utils.h"

std::string Utils::GenerateUUID() {
    const auto id = gen();
    return boost::uuids::to_string(id);
}
