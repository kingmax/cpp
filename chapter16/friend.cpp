// forward declare
template <typename> class Pal;

class C
{
	friend class Pal<C>;
	
	template <typename T> friend class Pal2;
};

template <typename T> 
class C2
{
	friend class Pal<T>;
	template <typename X> friend class Pal2;
	friend class Pal3;
};

template<typename T> using twin = pair<T, T>;
twin<string> authors; // authors is pair<string, string>
twin<int> win_loss;
twin<double> area;

template <typename T> using partNo = pair<T, unsigned>;
partNo<string> books;
partNo<Vehicle> cars;
partNo<Student> kids; // kids is pair<Student, unsigned>