#include "Particle.h"

PSO::Particle::Particle(int dim)
	: x(dim), pbest_x(dim), v(dim),
	f(std::numeric_limits<double>::max()), pbest_f(f)
{

}

PSO::Particle::~Particle()
{
}

PSO::Particle::Particle(const Particle &that)
{
	x = that.x;
	pbest_x = that.pbest_x;
	v = that.v;
	f = that.f;
	pbest_f = that.pbest_f;
}

bool PSO::Particle::evaluate()
{
	if (f < pbest_f)
	{
		pbest_x = x;
		pbest_f = f;
		return true;
	}
	return false;
}

std::ostream& PSO::operator << (std::ostream& os, const PSO::Particle& p)
{
	os << "#x";
	for (auto v : p.x) { os << "\t" << v; }
	os << "\t" << p.f << "\n";
	os << "#pbest";
	for (auto v : p.pbest_x) { os << "\t" << v; }
	os << "\t" << p.pbest_f;
	return os;
}
