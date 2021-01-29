int N0 = 1e5;
int N;


mt19937 gen(random_device{}());
uniform_int_distribution dist{ 1,10 };

int x = dist(gen);
constexpr auto f = "{:06X}"sv;
constexpr auto sf = "%06x";

int main()
{
	{
		char buf[100];
		N = N0;
		auto a = steady_clock::now();
		while (N--)
		{
			snprintf(buf, 100, sf, x);
		}
		auto b = steady_clock::now();

		print("snprintf,  {},  {},{}\n", buf, duration_cast<milliseconds>(b - a), (b - a) / N0);
	}


	{
		string buf;
		N = N0;
		auto a = steady_clock::now();
		while (N--)
		{
			buf = format(f, x);
		}
		auto b = steady_clock::now();

		print("format,  {},  {},{}\n", buf, duration_cast<milliseconds>(b - a), (b - a) / N0);
	}

	{
		string buf;
		N = N0;
		auto a = steady_clock::now();
		while (N--)
		{
			buf.clear();
			format_to(back_inserter(buf), f, x);
		}
		auto b = steady_clock::now();

		print("format_to,  {},  {},{}\n", buf, duration_cast<milliseconds>(b - a), (b - a) / N0);
	}

	{
		string buf;
		N = N0;
		auto a = steady_clock::now();
		while (N--)
		{
			buf = format(FMT_COMPILE(f), x);
		}
		auto b = steady_clock::now();

		print("format FMT_COMPILE,  {},  {},{}\n", buf, duration_cast<milliseconds>(b - a), (b - a) / N0);
	}


	{
		N = N0;
		auto a = steady_clock::now();
		string buf;
		while (N--)
		{
			buf.clear();
			format_to(back_inserter(buf), FMT_COMPILE(f), x);
		}
		auto b = steady_clock::now();

		print("format_to FMT_COMPILE,  {},  {},{}\n", buf, duration_cast<milliseconds>(b - a), (b - a) / N0);
	}

}