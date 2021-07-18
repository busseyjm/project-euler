//borrowed from https://www.learncpp.com/cpp-tutorial/timing-your-code/

#include <chrono> // for std::chrono functions
#include <iostream>
 
class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	using ms_t = std::chrono::duration<double, std::ratio<1,1000> >;
	
  double sec_elapsed;
  double ms_elapsed;
  bool running = false;

	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now()), running(true)
	{
	}
	
	void start()
	{
    running=true;
		m_beg = clock_t::now();
	}
	
	void stop()
	{
    sec_elapsed = std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
		ms_elapsed = std::chrono::duration_cast<ms_t>(clock_t::now() - m_beg).count();
    running=false;
	}

  double getms() { return ms_elapsed; }
  double getsec() { return sec_elapsed; }

  void printms() {
    if (running) stop();
    std::cout << ms_elapsed << "ms" << std::endl;
  }
  void printsec() {
    if (running) stop();
    std::cout << sec_elapsed << " seconds." << std::endl;
  }
};