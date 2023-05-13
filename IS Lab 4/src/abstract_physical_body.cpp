#include "../include/abstract_physical_body.h"

bool AbstractPhysicalBody::operator==(AbstractPhysicalBody object) const {
  return mass == object.mass;
}

bool AbstractPhysicalBody::operator!=(AbstractPhysicalBody object) const {
  return mass != object.mass;
}

bool AbstractPhysicalBody::operator<(AbstractPhysicalBody object) const {
  return mass < object.mass;
}

bool AbstractPhysicalBody::operator<=(AbstractPhysicalBody object) const {
  return mass <= object.mass;
}

bool AbstractPhysicalBody::operator>(AbstractPhysicalBody object) const {
  return mass > object.mass;
}

bool AbstractPhysicalBody::operator>=(AbstractPhysicalBody object) const {
  return mass >= object.mass;
}
