#include<bits/stdc++.h>
#include "CycleTimer.h"
#include<omp.h>

using namespace std;
typedef long long ll;
string Move(string state, int opt);

void CW(vector<char> &v1, vector<char> &v2, vector<char> &v3){
    char t1 = v1[0];
    char t2 = v1[1];
    char t3 = v1[2];
    char t4 = v2[0];
    char t5 = v2[1];
    char t6 = v2[2];
    char t7 = v3[0];
    char t8 = v3[1];
    char t9 = v3[2];

    v1[0] = t7; v1[1] = t4, v1[2] = t1;
    v2[0] = t8; v2[1] = t5, v2[2] = t2;
    v3[0] = t9; v3[1] = t6, v3[2] = t3;
}

// FrontCW
void rotate1(vector<vector<char>> &v){
    CW(v[6], v[7], v[8]);

    char temp1[3];
    temp1[0] = v[2][0];
    temp1[1] = v[2][1];
    temp1[2] = v[2][2];

    char temp2[3];
    temp2[0] = v[9][0];
    temp2[1] = v[10][0];
    temp2[2] = v[11][0];

    char temp3[3];
    temp3[0] = v[15][0];
    temp3[1] = v[15][1];
    temp3[2] = v[15][2];

    char temp4[3];
    temp4[0] = v[3][2];
    temp4[1] = v[4][2];
    temp4[2] = v[5][2];

    v[2][0] = temp4[2];
    v[2][1] = temp4[1];
    v[2][2] = temp4[0];

    v[9][0] = temp1[0];
    v[10][0] = temp1[1];
    v[11][0] = temp1[2];

    v[15][0] = temp2[2];
    v[15][1] = temp2[1];
    v[15][2] = temp2[0];

    v[3][2] = temp3[0];
    v[4][2] = temp3[1];
    v[5][2] = temp3[2];

}
// FrontACW
void rotate2(vector<vector<char>> &v){
    rotate1(v);
    rotate1(v);
    rotate1(v);
}
// UpCW
void rotate3(vector<vector<char>> &v){
    CW(v[0], v[1], v[2]);

    char temp1[3];
    temp1[0] = v[12][0];
    temp1[1] = v[12][1];
    temp1[2] = v[12][2];

    char temp2[3];
    temp2[0] = v[9][0];
    temp2[1] = v[9][1];
    temp2[2] = v[9][2];

    char temp3[3];
    temp3[0] = v[6][0];
    temp3[1] = v[6][1];
    temp3[2] = v[6][2];

    char temp4[3];
    temp4[0] = v[3][0];
    temp4[1] = v[3][1];
    temp4[2] = v[3][2];

    v[12][0] = temp4[0];
    v[12][1] = temp4[1];
    v[12][2] = temp4[2];

    v[9][0] = temp1[0];
    v[9][1] = temp1[1];
    v[9][2] = temp1[2];

    v[6][0] = temp2[0];
    v[6][1] = temp2[1];
    v[6][2] = temp2[2];

    v[3][0] = temp3[0];
    v[3][1] = temp3[1];
    v[3][2] = temp3[2];

}
// UpACW
void rotate4(vector<vector<char>> &v){
    rotate3(v);
    rotate3(v);
    rotate3(v);
}
// DownCW
void rotate5(vector<vector<char>> &v){
    CW(v[15], v[16], v[17]);

    char temp1[3];
    temp1[0] = v[8][0];
    temp1[1] = v[8][1];
    temp1[2] = v[8][2];

    char temp2[3];
    temp2[0] = v[11][0];
    temp2[1] = v[11][1];
    temp2[2] = v[11][2];

    char temp3[3];
    temp3[0] = v[14][0];
    temp3[1] = v[14][1];
    temp3[2] = v[14][2];

    char temp4[3];
    temp4[0] = v[5][0];
    temp4[1] = v[5][1];
    temp4[2] = v[5][2];

    v[8][0] = temp4[0];
    v[8][1] = temp4[1];
    v[8][2] = temp4[2];

    v[11][0] = temp1[0];
    v[11][1] = temp1[1];
    v[11][2] = temp1[2];

    v[14][0] = temp2[0];
    v[14][1] = temp2[1];
    v[14][2] = temp2[2];

    v[5][0] = temp3[0];
    v[5][1] = temp3[1];
    v[5][2] = temp3[2];

}
// DownACW
void rotate6(vector<vector<char>> &v){
    rotate5(v);
    rotate5(v);
    rotate5(v);
}
// LeftCW
void rotate7(vector<vector<char>> &v){
    CW(v[3], v[4], v[5]);

    char temp1[3];
    temp1[0] = v[0][0];
    temp1[1] = v[1][0];
    temp1[2] = v[2][0];

    char temp2[3];
    temp2[0] = v[6][0];
    temp2[1] = v[7][0];
    temp2[2] = v[8][0];

    char temp3[3];
    temp3[0] = v[15][0];
    temp3[1] = v[16][0];
    temp3[2] = v[17][0];

    char temp4[3];
    temp4[0] = v[12][2];
    temp4[1] = v[13][2];
    temp4[2] = v[14][2];

    v[0][0] = temp4[2];
    v[1][0] = temp4[1];
    v[2][0] = temp4[0];

    v[6][0] = temp1[0];
    v[7][0] = temp1[1];
    v[8][0] = temp1[2];

    v[15][0] = temp2[0];
    v[16][0] = temp2[1];
    v[17][0] = temp2[2];

    v[12][2] = temp3[2];
    v[13][2] = temp3[1];
    v[14][2] = temp3[0];

}
// LeftACW
void rotate8(vector<vector<char>> &v){
    rotate7(v);
    rotate7(v);
    rotate7(v);
}
// RightCW
void rotate9(vector<vector<char>> &v){
    CW(v[9], v[10], v[11]);

    char temp1[3];
    temp1[0] = v[0][2];
    temp1[1] = v[1][2];
    temp1[2] = v[2][2];

    char temp2[3];
    temp2[0] = v[12][0];
    temp2[1] = v[13][0];
    temp2[2] = v[14][0];

    char temp3[3];
    temp3[0] = v[15][2];
    temp3[1] = v[16][2];
    temp3[2] = v[17][2];

    char temp4[3];
    temp4[0] = v[6][2];
    temp4[1] = v[7][2];
    temp4[2] = v[8][2];

    v[0][2] = temp4[0];
    v[1][2] = temp4[1];
    v[2][2] = temp4[2];

    v[12][0] = temp1[2];
    v[13][0] = temp1[1];
    v[14][0] = temp1[0];

    v[15][2] = temp2[2];
    v[16][2] = temp2[1];
    v[17][2] = temp2[0];

    v[6][2] = temp3[0];
    v[7][2] = temp3[1];
    v[8][2] = temp3[2];

}
// RightACW
void rotate10(vector<vector<char>> &v){
    rotate9(v);
    rotate9(v);
    rotate9(v);
}
// BackCW
void rotate11(vector<vector<char>> &v){
    CW(v[12], v[13], v[14]);

    char temp1[3];
    temp1[0] = v[0][0];
    temp1[1] = v[0][1];
    temp1[2] = v[0][2];

    char temp2[3];
    temp2[0] = v[3][0];
    temp2[1] = v[4][0];
    temp2[2] = v[5][0];

    char temp3[3];
    temp3[0] = v[17][0];
    temp3[1] = v[17][1];
    temp3[2] = v[17][2];

    char temp4[3];
    temp4[0] = v[9][2];
    temp4[1] = v[10][2];
    temp4[2] = v[11][2];

    v[0][0] = temp4[0];
    v[0][1] = temp4[1];
    v[0][2] = temp4[2];

    v[3][0] = temp1[2];
    v[4][0] = temp1[1];
    v[5][0] = temp1[0];

    v[17][0] = temp2[0];
    v[17][1] = temp2[1];
    v[17][2] = temp2[2];

    v[9][2] = temp3[2];
    v[10][2] = temp3[1];
    v[11][2] = temp3[0];

}
// BackACW
void rotate12(vector<vector<char>> &v){
    rotate11(v);
    rotate11(v);
    rotate11(v);
}


string to_state(vector<vector<char>> &v){
    string s = "";
    for(int i=0;i<18;++i){
        for(int j=0;j<3;++j){
            s += v[i][j];
        }
    }
    return s;
}

vector<vector<char>> to_node(string &s){
    char tmp[3];
    vector<vector<char>> v;
    for(int i=0;i<54;++i){
        if(i % 3 == 0){
            tmp[0] = s[i];
        }else if(i % 3 == 1){
            tmp[1] = s[i];
        }else{
            tmp[2] = s[i];
            vector<char> temp(tmp,tmp+3);
            v.push_back(temp);
        }
    }

    return v;
}

bool goal(string s){
    for(int i=0;i<54;i+=9){
        char tmp = s[i];
        for(int j=0;j<9;j++){
            if(s[i+j] != tmp){
                return 0;
            }
        }
    }
    return 1;
}

unordered_map<string,int> used_state;
string final_state = "";

int manhattan_distance(string &state, int i, int z, bool corner){
	string arr = "002102202001101201000100200002012022001011021000010020000100200010110210020120220200201202210211212220221222202102002212112012222122022020120220021121221022122222";
	char c1_0 = arr[9*i + 3*z];
 	char c1_1 = arr[9*i + 3*z + 1];
 	char c1_2 = arr[9*i + 3*z + 2];

    int center = -1;
    char c2_0, c2_1, c2_2;
    vector<vector<char>> cube = to_node(state);
    for(int c=1; c<=16; c+=3){
    	if( cube[i][z] == cube[c][1] ){
    		center = c;
    		break;
    	}
    }
    
    /*int minimum=INT_MAX, d[4];
    if(corner){
        #pragma omp parallel for
        for(int i =0; i<2; i++){
            c2_0 = arr[9*(center-1) + 3*2*i];
            c2_1 = arr[9*(center-1) + 3*2*i + 1];
            c2_2 = arr[9*(center-1) + 3*2*i + 2];
            d[i] = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        }
        #pragma omp parallel for
        for(int i =0; i<2; i++){
            c2_0 = arr[9*(center+1) + 3*2*i];
            c2_1 = arr[9*(center+1) + 3*2*i + 1];
            c2_2 = arr[9*(center+1) + 3*2*i + 2];
            d[i+2] = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        }
        for(int i=0; i<4; i++){
            if(d[i]<minimum) 
                minimum = d[i];
        }
    }else{
        #pragma omp parallel for
        for(int i =0; i<2; i++){
            c2_0 = arr[9*center + 3*2*i];
            c2_1 = arr[9*center + 3*2*i + 1];
            c2_2 = arr[9*center + 3*2*i + 2];
            d[2*i] = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        }
        #pragma omp parallel for
        for(int i =-1; i<2; i+=2){
            c2_0 = arr[9*(center+i) + 3*1];
            c2_1 = arr[9*(center+i) + 3*1 + 1];
            c2_2 = arr[9*(center+i) + 3*1 + 2];
            d[i+2] = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        }
        for(int i=0; i<4; i++){
            if(d[i]<minimum) 
                minimum = d[i];
        }

    }*/

    
    int d1, d2, d3 ,d4, minimum;
    if(corner){
        //c2 = array[center - 1, 0]
        c2_0 = arr[9*(center-1) + 3*0];
 		c2_1 = arr[9*(center-1) + 3*0 + 1];
 		c2_2 = arr[9*(center-1) + 3*0 + 2];
        d1 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        minimum = d1;
        //c2 = array[center - 1, 2]
        c2_0 = arr[9*(center-1) + 3*2];
 		c2_1 = arr[9*(center-1) + 3*2 + 1];
 		c2_2 = arr[9*(center-1) + 3*2 + 2];
        d2 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d2<minimum){ minimum = d2; }
        //c2 = array[center + 1, 0]
        c2_0 = arr[9*(center+1) + 3*0];
 		c2_1 = arr[9*(center+1) + 3*0 + 1];
 		c2_2 = arr[9*(center+1) + 3*0 + 2];
        d3 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d3<minimum){ minimum = d3; }
        //c2 = array[center + 1, 2]
        c2_0 = arr[9*(center+1) + 3*2];
 		c2_1 = arr[9*(center+1) + 3*2 + 1];
 		c2_2 = arr[9*(center+1) + 3*2 + 2];
        d4 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d4<minimum){ minimum = d4; }
    }else{
        //c2 = array[center - 1, 1]
        c2_0 = arr[9*(center-1) + 3*1];
 		c2_1 = arr[9*(center-1) + 3*1 + 1];
 		c2_2 = arr[9*(center-1) + 3*1 + 2];
        d1 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        minimum = d1;
        //c2 = array[center, 0]
        c2_0 = arr[9*center + 3*0];
 		c2_1 = arr[9*center + 3*0 + 1];
 		c2_2 = arr[9*center + 3*0 + 2];
        d2 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d2<minimum){ minimum = d2; }
        //c2 = array[center, 2]
        c2_0 = arr[9*center + 3*2];
 		c2_1 = arr[9*center + 3*2 + 1];
 		c2_2 = arr[9*center + 3*2 + 2];
        d3 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d3<minimum){ minimum = d3; }
        //c2 = array[center + 1, 1]
        c2_0 = arr[9*(center+1) + 3*1];
 		c2_1 = arr[9*(center+1) + 3*1 + 1];
 		c2_2 = arr[9*(center+1) + 3*1 + 2];
        d4 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d4<minimum){ minimum = d4; }
    }

    return minimum;
}

int corner_edge_sum_max(string &state){
	int corners = 0;
	int edges = 0;

    /*
    //Another method
    int corners_mat[18];
    int edges_mat[18];
    #pragma omp parallel for
    for(int i=0; i<18; i+=3){
        corners_mat[i] = manhattan_distance(state, i, 0, true) + manhattan_distance(state, i, 2, true);
        corners_mat[i+1] = 0;
        corners_mat[i+2] = manhattan_distance(state, i+2, 0, true) + manhattan_distance(state, i+2, 2, true);
        edges_mat[i] = manhattan_distance(state, i, 1, false);
        edges_mat[i+1] = manhattan_distance(state, i+1, 0, false) + manhattan_distance(state, i+1, 2, false);
        edges_mat[i+2] = manhattan_distance(state, i+2, 1, false);        
    }
    #pragma omp parallel for reduction(+:corners, edges)
    for(int i=0; i<18; i++){
        corners = corners + corners_mat[i];
        edges = edges + edges_mat[i];
    }*/

    #pragma omp parallel for reduction(+:corners, edges)
    for(int i=0; i<18; i+=3){
        corners = corners + manhattan_distance(state, i, 0, true) + manhattan_distance(state, i, 2, true);
        corners = corners + manhattan_distance(state, i+2, 0, true) + manhattan_distance(state, i+2, 2, true);
        edges = edges + manhattan_distance(state, i, 1, false);
        edges = edges + manhattan_distance(state, i+1, 0, false) + manhattan_distance(state, i+1, 2, false);
        edges = edges + manhattan_distance(state, i+2, 1, false);        
    }
    
	/*for(int i=0; i<18; i++){
		if(i % 3 == 0 || i % 3 == 2){
			corners = corners + manhattan_distance(state, i, 0, true) + manhattan_distance(state, i, 2, true);
            edges = edges + manhattan_distance(state, i, 1, false);
		}else{
			edges = edges + manhattan_distance(state, i, 0, false) + manhattan_distance(state, i, 2, false);
		}
	}*/

	int sum_max;
	if( (corners/12) >= (edges/8) ){
		sum_max = (corners/12);
	}else{
		sum_max = (edges/8);
	}
	return sum_max;
}

class node{
public:
    string state;
    int f, g, h;
    node(string s, int g_in){
        state = s;
        g = g_in;
        h = corner_edge_sum_max(state);
        f = g + h;
    }
};

int IDA(vector<vector<char>> &v){
    used_state.clear();
	vector<vector<char>> start_node = v;
    string start_state = to_state(start_node);
    queue<string> q;
    queue<int> q_g;

 	int minimum = -1;
 	int cost_limit = corner_edge_sum_max(start_state);
    q.push(start_state);
    q_g.push(0);

    while(1){
    	minimum=-1;
    	q.push(start_state);
    	q_g.push(0);

	    while(!q.empty()){
	        string curr_state = q.front();
	        string next_state = "";
	        int curr_g = q_g.front();
	        q.pop();
	        q_g.pop();

            int new_g = curr_g + 1;
	        for(int i=1;i<=12;++i){
	            next_state = Move(curr_state, i);

	            if(goal(next_state)){
	                used_state[next_state] = i;
	                final_state = next_state;
                    return new_g;
	            }else{
	            	int new_h = corner_edge_sum_max(next_state);
	            	if( new_g + new_h > cost_limit){
	            		if (minimum == -1 || (new_g + new_h < minimum) ){
	            			minimum = new_g + new_h;
	            		}
	            		continue;
	            	}

	            	if(used_state.count(next_state) == 1){
	            		continue;
	            	}

	                used_state[next_state] = i;

                    node next_node(next_state, new_g);
	                q.push(next_state);
	                q_g.push(new_g);
	            }
	        }

	    }

	    used_state.clear();
	    cost_limit = minimum;
	}

    return 0;


}

int BFS(vector<vector<char>> &v){
    vector<vector<char>> start_node = v;
    string start_state = to_state(start_node);
    queue<string> q;
    queue<int> q_cnt;

    q.push(start_state);
    used_state.clear();
    used_state[start_state] = -1;
    q_cnt.push(1);

    while(!q.empty()){
        string curr_state = q.front();
        string next_state = "";
        int cnt = q_cnt.front();
        q.pop();
        q_cnt.pop();

        for(int i=1;i<=12;++i){
            next_state = Move(curr_state, i);

            if(goal(next_state)){
                used_state[next_state] = i;
                final_state = next_state;
                return cnt;
            }else if(used_state.count(next_state) != 1){
                used_state[next_state] = i;
                q.push(next_state);
                q_cnt.push(cnt + 1);
            }
        }
    }

    return 0;
}

struct cmp{
    bool operator()(node &a, node &b){
        return a.f > b.f;
    }
};

int A_star(vector<vector<char>> &v){
    vector<vector<char>> start_node = v;
    string start_state = to_state(start_node);
    priority_queue<node, vector<node>, cmp> pq;

    node node_start(start_state, 0);
    pq.push(node_start);
    //used_state.clear();
    //used_state[start_state] = -1;
    unordered_set<ll> used;
    hash<string> H;
    used.insert(H(start_state));
    
    int total_nodes = 0;
    while(!pq.empty()){
        string curr_state = pq.top().state;
        int curr_g = pq.top().g;
        //string next_state = "";
        pq.pop();
        int next_g = curr_g + 1;
	
	volatile bool flag = 0;
	string nextState[12];
	#pragma omp parallel for
        for(int i=1;i<=12;++i){
	    if(flag){
                continue;
            }

            string next_state = Move(curr_state, i);
	    nextState[i-1] = next_state;
            if(goal(next_state)){
                //used_state[next_state] = i;
                final_state = next_state;
                //return next_g;
		flag = 1;
            }
        }
	#pragma omp barrier

	if(flag){
	    cout << "num nodes: " << total_nodes << endl;
            return next_g;
        }
	
	for(int i=0;i<12;++i){
	    //if(used_state.count(nextState[i]) != 1){
	    if(used.count(H(nextState[i])) != 1){
                node next_node(nextState[i], next_g);
                //used_state[nextState[i]] = i + 1;
		used.insert(H(nextState[i]));
                pq.push(next_node);
		total_nodes++;
            }
	}
    }
    return 0;

}


string Move(string state, int opt){
    vector<vector<char>> vec = to_node(state);
    if(opt == 1){
        rotate1(vec);
    }else if(opt == 2){
        rotate2(vec);
    }else if(opt == 3){
        rotate3(vec);
    }else if(opt == 4){
        rotate4(vec);
    }else if(opt == 5){
        rotate5(vec);
    }else if(opt == 6){
        rotate6(vec);
    }else if(opt == 7){
        rotate7(vec);
    }else if(opt == 8){
        rotate8(vec);
    }else if(opt == 9){
        rotate9(vec);
    }else if(opt == 10){
        rotate10(vec);
    }else if(opt == 11){
        rotate11(vec);
    }else if(opt == 12){
        rotate12(vec);
    }

    return to_state(vec);
}

int main(){
    string s;
    vector<vector<char>> vec_input;
    vector<vector<char>> vec1;
    vector<vector<char>> vec2;
    vector<vector<char>> vec3;
    vector<vector<char>> vec4;
    for(int i=0;i<9;++i){
        cin >> s;
        if(i>=0 && i<3){
            char tmp[3];
            tmp[0] = s[3];
            tmp[1] = s[4];
            tmp[2] = s[5];
            vec_input.push_back(vector<char>(tmp,tmp+3));
        }else if(i>=3 && i<6){
            char tmp1[3]; tmp1[0] = s[0]; tmp1[1] = s[1];  tmp1[2] = s[2];
            char tmp2[3]; tmp2[0] = s[3]; tmp2[1] = s[4];  tmp2[2] = s[5];
            char tmp3[3]; tmp3[0] = s[6]; tmp3[1] = s[7];  tmp3[2] = s[8];
            char tmp4[3]; tmp4[0] = s[9]; tmp4[1] = s[10]; tmp4[2] = s[11];
            vec1.push_back(vector<char>(tmp1,tmp1+3));
            vec2.push_back(vector<char>(tmp2,tmp2+3));
            vec3.push_back(vector<char>(tmp3,tmp3+3));
            vec4.push_back(vector<char>(tmp4,tmp4+3));
        }else{
            if(i == 6){
                for(const auto &v: vec1){
                    vec_input.push_back(v);
                }
                for(const auto &v: vec2){
                    vec_input.push_back(v);
                }
                for(const auto &v: vec3){
                    vec_input.push_back(v);
                }
                for(const auto &v: vec4){
                    vec_input.push_back(v);
                }
            }
            char tmp[3];
            tmp[0] = s[3];
            tmp[1] = s[4];
            tmp[2] = s[5];
            vec_input.push_back(vector<char>(tmp,tmp+3));
        }
    }

    
    //rotate1(vec_input);
    //rotate12(vec_input);
    //rotate3(vec_input);
    //rotate9(vec_input);
    //rotate7(vec_input);
    //rotate2(vec_input);
    //rotate4(vec_input);

    for(int i=0;i<18;++i){
        for(int j=0;j<3;++j){
            cout << vec_input[i][j] << " ";
        }
        cout << endl;
    }



    /*
    {
        double startTime = CycleTimer::currentSeconds();
        //double s = clock();
        int steps = BFS(vec_input);
        //double e = clock();
        double endTime = CycleTimer::currentSeconds();
        cout << "\nBFS steps: " << steps << endl;
        printf("time: [%.3f] ms\n", (endTime - startTime) * 1000);
        //cout << "time: " << e - s << " ms" << endl;
    }
    cout << endl;
    */

    {
        double startTime = CycleTimer::currentSeconds();
        //double s = clock();
        int steps = A_star(vec_input);
        //double e = clock();
        double endTime = CycleTimer::currentSeconds();        
        cout << "\nA star steps: " << steps << endl;
        printf("time: [%.3f] ms\n", (endTime - startTime) * 1000);
        //cout << "time: " << e - s << " ms" << endl;
    }
    cout << endl;
    
    /*
    {
        double startTime = CycleTimer::currentSeconds();
        //double s = clock();
        int steps = IDA(vec_input);
        //double e = clock();
        double endTime = CycleTimer::currentSeconds();
        cout << "\nIDA star steps: " << steps << endl;
        printf("time: [%.3f] ms\n", (endTime - startTime) * 1000);
        //cout << "time: " << e - s << " ms" << endl;
    }
    cout << endl;
    */
    
    

    

    /*
    int opt;
    string state = final_state;
    fstream file;
    file.open("cube_states.txt", ios::out);

    while(1){
        cout << state << endl;
        file << state << endl;
        opt = used_state[state];
        if(opt == -1){
            break;
        }
        if(opt % 2){
            opt++;
        }else{
            opt--;
        }
        cout << opt << endl;
        file << opt << endl;

        state = Move(state, opt);
    }*/


    //cout << "\nsteps: " << steps << endl;


    //file.close();
	return 0;
}

/*
initial:
000111000000
000111000000
000111000000
222333444555
222333444555
222333444555
000666000000
000666000000
000666000000

steps 2:
000315000000
000315000000
000315000000
222631444651
222631444651
222631444651
000563000000
000563000000
000563000000

steps 1:
000511000000
000511000000
000511000000
222133444556
222133444556
222133444556
000366000000
000366000000
000366000000

steps 5:
000515000000
000515000000
000322000000
224111544636
224133644656
113233644654
000122000000
000563000000
000563000000

steps 8:
000351000000 
000412000000
000452000000
211345664521
622331241355
312331245666
000665000000
000563000000
000444000000

steps 6:
000515000000 
000515000000
000344000000
221211344636
222331244656
112331244654
000665000000
000563000000
000563000000

steps 6:
000122000000
000244000000
000336000000
451223561416
623511664555
513511664522
000233000000
000433000000
000446000000

steps 7:
000122000000
000515000000
000344000000
521211345664
622331241355
312331245666
000665000000
000563000000
000444000000
*/
