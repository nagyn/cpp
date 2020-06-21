#pragma once
#define S 5
namespace knihovna
{

	struct List
	{
		int vertex;
		List *next;
	};
	typedef List TList;
	bool findway(TList **top, int graphdfs[S][S], bool dfsvisited[S], int start, int finish);
	void bigpart(int graf[S][S]);

} // namespace knihovna
