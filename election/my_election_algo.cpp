
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class process{

public:
    int proc_id;
    bool is_active;

    process(int _id){
        proc_id = _id;
        is_active = true;
    }

    bool send_message (){
        return is_active;
    }

    //ring election message circulation

    void bcast_bully (vector<process> processes){
        int itr = proc_id;
        int num_flag = 0;
        bool is_bully = true;
        cout<<endl<<"executing for proc "<<proc_id;
        for(process cur : processes){
            num_flag = cur.ask_if_active(processes, this->proc_id);
            if(num_flag > this->proc_id){
                is_bully = false;
                cout<<endl<<"process "<<proc_id<<" denied by "<<num_flag; 
                break;
            }
        }
        if(is_bully){
            cout<<endl<<"Process no "<<this->proc_id<<" is the new leader";
        }
    }

    int ask_if_active(vector<process> processes, int asked_by){
        if(asked_by < this->proc_id && this->is_active){
            this->bcast_bully(processes);
        }
        if(!this->is_active){
            return 0;
        }
        else{
            return this->proc_id;
        }
    }

};

int main(){
    
    //generate processes
    int no_of_proc = 5;
    vector<process> processes;
    for(int i = 1; i<=no_of_proc; i++){
        process newProcess(i);
        processes.push_back(newProcess);
    }
    
    //set highest to inactive
    processes[no_of_proc - 1].is_active = false;

    //set host/ coordinator
    int host_proc_no = 2;
    
    //implement ring algorithm
    int itr = (host_proc_no + 1) % no_of_proc;
    vector<int> active_procs = {host_proc_no};
    while(itr%no_of_proc != host_proc_no){
        if(processes[itr%no_of_proc-1].is_active){
            active_procs.push_back(itr%no_of_proc);
        }
        itr++;
    }
    for(int i : active_procs){
        cout<<endl<<i;
    }
    cout<<"\n new coordinator is: "<< *max_element(active_procs.begin(), active_procs.end());

    //---------------------------implement bully algo---------------------------------

    processes[host_proc_no-1].bcast_bully(processes);

    return 0;
}