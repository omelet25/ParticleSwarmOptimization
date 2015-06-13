#include "BasePSO.h"

PSO::BasePSO::BasePSO(CostFunction func, int itr, int pop)
	: _itr(itr), _pop(pop),
	_gbest_x(func.get_dim()), _gbest_f(std::numeric_limits<double>::max()),
	_particles(pop), _func(func)
{
	/* —”¶¬Ší‚Ì‰Šú‰» */
	std::random_device rnd;
	_mt = std::mt19937(rnd());
	_urd = std::uniform_real_distribution<>(0.0, 1.0);

	for (int i = 0; i < pop; i++)
	{
		_particles[i] = Particle(func.get_dim());
	}
}

PSO::BasePSO::~BasePSO()
{
}

void PSO::BasePSO::initialize()
{
	for (int i = 0; i < _pop; i++)
	{
		for (int j = 0; j < _func.get_dim(); j++)
		{
			_particles[i].pbest_x[j] = _particles[i].x[j] = uniform(_func.get_min(), _func.get_max());
			_particles[i].v[j] = uniform(-_func.get_euclid() / 2.0, _func.get_euclid() / 2.0);
		}
		_particles[i].pbest_f = _particles[i].f = _func.get_cost(_particles[i].x);
	}
}

void PSO::BasePSO::Start()
{
	initialize();
	int t = 0;
	while (true)
	{
		evaluate();
		results.push_back({ t, _gbest_x, _gbest_f });
		std::cout << t << "\t" << results[t].gbest_f << std::endl;
		if (++t >= _itr) { break; }
		update();
	}
}

void PSO::BasePSO::evaluate()
{
	for (int i = 0; i < _pop; i++)
	{
		// —±q•]‰¿
		if (_particles[i].evaluate())
		{
			// —±qŒQ•]‰¿
			if (_particles[i].pbest_f < _gbest_f)
			{
				_gbest_f = _particles[i].pbest_f;
				_gbest_x = _particles[i].pbest_x;
			}
		}
	}
}

double PSO::BasePSO::uniform(double min, double max)
{
	return (max - min) *_urd(_mt) + min;
}

double PSO::BasePSO::set_domain(double val, double min, double max)
{
	if (val < min) { return min; }
	else if (val > max) { return max; }
	else { return val; }
}