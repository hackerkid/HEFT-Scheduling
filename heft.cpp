#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <utility>
#include <algorithm>
#include <limits.h>
using namespace std;

double rank[100];
double avg[100];
int adj[100][100];
int task_time[100l][50];
int proc;
int tasks;
int eft[100][50];
int est[100][50];
int aft[100];
vector <int> parent[100];
int mini_processor[100];
vector < pair <double, int> > rank_task;


class processor_slot
{
	public:
		int start_time;
		int end_time;
		int task_no;

};


vector <processor_slot> processor_scheduler[100];

double rec_rank(int i)
{
    double maxi = 0;
	double temp;

    for (int j = 0; j < proc; j++) {
        if(adj[i][j] != -1) {
			temp = rec_rank(j);
            if (maxi < adj[i][j] + temp)
                maxi = adj[i][j] + temp;
            }

    }
    rank[i] = avg[i] + maxi;
    return rank[i];
}

int est_cal(int i, int j)
{
	int comm;
	int par;
	int max_time;
	int temp = 0;;

	max_time = 0;

	for (int k = 0; k < parent[i].size(); k++) {
		par = parent[i][k];
		if(mini_processor[par] == j) {
			temp = aft[par];
		}

		else {
			temp = adj[par][i] + aft[par];
		}

		max_time = max(max_time, temp);
	}

	return max_time;

}
			




int eft_cal(int i, int j)
{
		int start_time;
		
		if(processor_scheduler[j].empty()) {
			return est[i][j] + task_time[i][j];
		}
		/*
		for (int k = 0; k < processor_scheduler[j].length() -1 ; k++) {
			if( processor_scheduler[j][k].end_time > est[i][j] and processor_scheduler[j][k+1].start_time > est[i][j] + task_time[i][j]) {
				return est[i][j] + task_time[i][j];
			}

		}

		return processor_scheduler[

		*/
		int ok;
		int endtime;
		ok = 1;
		for (int timer = est[i][j]; 1; timer++) {
			ok = 1;
			endtime = timer + task_time[i][j];
			for (int k = 0; k < processor_scheduler[j].size(); k++) {
				//temp = processor_scheduler[j];

				if((timer < processor_scheduler[j][k].start_time and endtime > processor_scheduler[j][k].start_time) or (timer < processor_scheduler[j][k].end_time and endtime > processor_scheduler[j][k].end_time) ) {
					ok = 0;
					break;
				}


			}

			if(ok == 1) {
				return endtime;
			}

		}


}


void heft()
{
	int mini;
	mini = INT_MAX;
	int t;
	int mini_eft;
	int length = -1;

	processor_slot temp;
	processor_slot temp2;
	t = rank_task[0].second;

	for (int i = 0; i < proc; i++) {
		est[rank_task[0].second][i] = 0;
		if(mini > task_time[t][i]) {
			mini = task_time[t][i];
			mini_processor[t] = i;
		}

	}

	temp.start_time = 0;
	temp.end_time = mini;
	temp.task_no = t;

	processor_scheduler[mini_processor[t]].push_back(temp);

	aft[rank_task[0].second] = mini;
	int i;
	for (int h = 1; h < tasks; h++) {
		i = rank_task[h].second;

		for (int j = 0; j < proc; j++) {
			est[i][j] = est_cal(i, j);

		}
	
		mini_eft = INT_MAX;
		int processor_no = 0;

		for (int j = 0; j < proc; j++) {
			eft[i][j] = eft_cal(i, j);
			if(eft[i][j] < mini_eft) {
				mini_eft = eft[i][j];
				processor_no = j;
			}
		}
		
		mini_processor[i] = processor_no;
		
		temp2.start_time = mini_eft - task_time[i][processor_no];
		temp2.end_time = mini_eft;
		aft[i] = mini_eft;
		temp2.task_no = i;
		length = max(mini_eft, length);

		processor_scheduler[processor_no].push_back(temp2);

	}

	for (int i = 0; i < proc; i++) {
		for (int j = 0; j < processor_scheduler[i].size(); j++) {
			cout << " rank => " << rank[processor_scheduler[i][j].task_no] << "start time " << processor_scheduler[i][j].start_time;
		}
		cout << endl;

	}

	cout << length << endl;

	



	
}

	

	
int main()
{
    int x;
    int y;
    int z;
    int n;
    float ans;
    int p;
	double temp;
	int edges_count;


	
	memset(adj, -1, sizeof(adj));

	cout << "Enter number of tasks and pocessors\n";

    cin >> tasks >> proc;
    for (int i = 0; i < tasks; i++) {
		temp = 0;
    	for (int j = 0; j < proc; j++) {
			cin >> task_time[i][j];
			temp += task_time[i][j];
		}
		avg[i] = (double) temp / (double) proc;
	}

	cout << "Number of edges for graph\n";
	cin >> edges_count;

	for (int i = 0; i < edges_count; i++) {
		cin >> x >> y >> z;
		adj[x][y] = z;
		parent[y].push_back(x);
	}
    
	for (int i = 0; i < tasks; i++) {
        rec_rank(i);
    }



    for (int i = 0; i < tasks; i++) {
		rank_task.push_back(make_pair(rank[i], i));
    }

	sort(rank_task.rbegin(), rank_task.rend());
    
	for (int i = 0; i < tasks; i++) {
    }

	heft();

    return 0;

}
