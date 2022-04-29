#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int r_score;
    int b_score;
    int arr[3][3];
    node(int a[3][3]){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                this->arr[i][j]=a[i][j];
            }
        }
        r_score=0;
        b_score=0;
    };

    node(node nd,int r,int b){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                this->arr[i][j]=nd.arr[i][j];
            }
        }
        this->r_score=r;
        this->b_score=b;
    }
    void print_node(){
      
        cout<<"R score : "<<r_score<<endl;
        cout<<"B score : "<<b_score<<endl;
      cout<<endl;
        cout<<"0  1  2"<<endl;
        cout<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                if(j==3){
                    cout<<" "<<i<<endl;
                }
                else{
                if(this->arr[i][j]==0){
                    cout<<"R"<<" ";
                }
                else if(this->arr[i][j]==1)
                    cout<<"B"<<" ";
                else{cout<<"* ";}
                }
                
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
int check_0_0(node obj,int tp){
    int score=1;
    if(obj.arr[0][1]!=-1){
        if(obj.arr[0][1]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    if(obj.arr[1][1]!=-1){
        if(obj.arr[1][1]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    if(obj.arr[1][0]!=-1){
        if(obj.arr[1][0]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    return score;
}
int check_0_1(node obj,int tp){
    int score=1;
    int n_min=0;
    if(obj.arr[0][0]!=-1&&obj.arr[1][0]!=-1&&obj.arr[1][1]!=-1){
        n_min=1;
        if(obj.arr[0][0]==tp){
            score++;
        }
        if(obj.arr[1][1]==tp){
            score++;
        }
        if(obj.arr[1][0]==tp){
            score++;
        }
    }
    
    int score1=1;
    if(obj.arr[0][2]!=-1&&obj.arr[1][2]!=-1&&obj.arr[1][1]!=-1){
        n_min=1;
        if(obj.arr[0][2]==tp){
            score1++;
        }
        if(obj.arr[1][1]==tp){
            score1++;
        }
        if(obj.arr[1][2]==tp){
            score1++;
        }
    }
    if(n_min==0){return 0;}
    return (score>score1)?score:score1;
}
int check_0_2(node obj,int tp){
    int score=1;
    if(obj.arr[0][1]!=-1){
        if(obj.arr[0][1]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    if(obj.arr[1][1]!=-1){
        if(obj.arr[1][1]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    if(obj.arr[1][2]!=-1){
        if(obj.arr[1][2]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    return score;
}

int check_1_0(node obj,int tp){
    int score=1;
    int n_min=0;
    if(obj.arr[0][0]!=-1&&obj.arr[0][1]!=-1&&obj.arr[1][1]!=-1){
        n_min=1;
        if(obj.arr[0][0]==tp){
            score++;
        }
        if(obj.arr[1][1]==tp){
            score++;
        }
        if(obj.arr[0][1]==tp){
            score++;
        }
    }
    int score1=1;
    if(obj.arr[2][0]!=-1&&obj.arr[2][1]!=-1&&obj.arr[1][1]!=-1){
        n_min=1;
        if(obj.arr[2][0]==tp){
            score1++;
        }
        if(obj.arr[1][1]==tp){
            score1++;
        }
        if(obj.arr[2][1]==tp){
            score1++;
        }
    }
    if(n_min==0){return 0;}
    return (score>score1)?score:score1;
}

int check_1_1(node obj,int tp){
    int n_min=0;
    int score=1;
    if(obj.arr[0][0]!=-1&&obj.arr[0][1]!=-1&&obj.arr[1][0]!=-1){
        n_min=1;
        if(obj.arr[0][0]==tp){
            score++;
        }
        if(obj.arr[0][1]==tp){
            score++;
        }
        if(obj.arr[1][0]==tp){
            score++;
        }
    }
    int score1=1;
    if(obj.arr[0][1]!=-1&&obj.arr[0][2]!=-1&&obj.arr[1][2]!=-1){
        n_min=1;
        if(obj.arr[0][1]==tp){
            score1++;
        }
        if(obj.arr[1][2]==tp){
            score1++;
        }
        if(obj.arr[0][2]==tp){
            score1++;
        }
    }
    int score2=1;
    if(obj.arr[2][0]!=-1&&obj.arr[1][0]!=-1&&obj.arr[2][1]!=-1){
        n_min=1;
        if(obj.arr[2][0]==tp){
            score2++;
        }
        if(obj.arr[2][1]==tp){
            score2++;
        }
        if(obj.arr[1][0]==tp){
            score2++;
        }
    }
    int score3=1;
    if(obj.arr[1][2]!=-1&&obj.arr[2][2]!=-1&&obj.arr[2][1]!=-1){
        n_min=1;
        if(obj.arr[1][2]==tp){
            score3++;
        }
        if(obj.arr[2][1]==tp){
            score3++;
        }
        if(obj.arr[2][2]==tp){
            score3++;
        }
    }
    if(n_min==0){return 0;}
    int max=score;
    if(max<score1){max=score1;};
    if(max<score2){max=score2;};
    if(max<score3){max=score3;};
    return max;
}

int check_1_2(node obj,int tp){
    int score=1;
    int n_min=0;
    if(obj.arr[0][1]!=-1&&obj.arr[0][2]!=-1&&obj.arr[1][1]!=-1){
        n_min=1;
        if(obj.arr[0][2]==tp){
            score++;
        }
        if(obj.arr[1][1]==tp){
            score++;
        }
        if(obj.arr[0][1]==tp){
            score++;
        }
    }
    int score1=1;
    if(obj.arr[2][2]!=-1&&obj.arr[2][1]!=-1&&obj.arr[1][1]!=-1){
        n_min=1;
        if(obj.arr[2][2]==tp){
            score1++;
        }
        if(obj.arr[1][1]==tp){
            score1++;
        }
        if(obj.arr[2][1]==tp){
            score1++;
        }
    }
  if(n_min==0){return 0;}
    return (score>score1)?score:score1;
}
int check_2_0(node obj,int tp){
    int score=1;
    if(obj.arr[1][0]!=-1){
        if(obj.arr[1][0]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    if(obj.arr[1][1]!=-1){
        if(obj.arr[1][1]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    if(obj.arr[2][1]!=-1){
        if(obj.arr[2][1]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    return score;
}
int check_2_1(node obj,int tp){
    int score=1;
    int n_min=0;
    if(obj.arr[1][0]!=-1&&obj.arr[2][0]!=-1&&obj.arr[1][1]!=-1){
        n_min=1;
        if(obj.arr[2][0]==tp){
            score++;
        }
        if(obj.arr[1][1]==tp){
            score++;
        }
        if(obj.arr[1][0]==tp){
            score++;
        }
    }
    int score1=1;
    if(obj.arr[2][2]!=-1&&obj.arr[1][2]!=-1&&obj.arr[1][1]!=-1){
        n_min=1;
        if(obj.arr[2][2]==tp){
            score1++;
        }
        if(obj.arr[1][1]==tp){
            score1++;
        }
        if(obj.arr[1][2]==tp){
            score1++;
        }
    }
    if(n_min==0){return 0;}
    return (score>score1)?score:score1;
}
int check_2_2(node obj,int tp){
    int score=1;
    if(obj.arr[1][2]!=-1){
        if(obj.arr[1][2]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    if(obj.arr[1][1]!=-1){
        if(obj.arr[1][1]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    if(obj.arr[2][1]!=-1){
        if(obj.arr[2][1]==tp){
            score++;
        }
    }
    else{
        score=0;
        return score;
    }
    return score;
}
int analyze_board(node obj,int i,int j,int tp){
    int val=0;
    if(i==0){
        if(j==0){
            val=check_0_0(obj,tp);
        }
        else if(j==1){
            val=check_0_1(obj,tp);
        }
        else{
            val=check_0_2(obj,tp);
        }
    }
    else if(i==1){
        if(j==0){
            val=check_1_0(obj,tp);
        }
        else if(j==1){
            val=check_1_1(obj,tp);
        }
        else{
            val=check_1_2(obj,tp);
        }
    }
    else{
        if(j==0){
            val=check_2_0(obj,tp);
        }
        else if(j==1){
            val=check_2_1(obj,tp);
        }
        else{
            val=check_2_2(obj,tp);
        }
    }
    return val;
}
// 0-->red
// 1-->blue
vector<node> generate_neigh(node obj,int tp){
    vector<node> temp;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(obj.arr[i][j]==-1){
                node temp1=obj.arr;
                temp1.arr[i][j]=tp;
                int score=analyze_board(temp1,i,j,tp);
                if(tp==0){
                    temp1.r_score+=score;
                }
                else{
                    temp1.b_score+=score;
                }
                temp.push_back(temp1);
            }
        }
    }
    return temp;
}
int eval_neigh(node obj,int tp){
    vector<node> neigh=generate_neigh(obj,tp);
    if(neigh.size()==0){
        return obj.r_score-obj.b_score;
    }
    else if(neigh.size()==1){
        return neigh[0].r_score-neigh[0].b_score;
    }
    else{
        vector<int> score;
        for(int i=0;i<neigh.size();i++){
            int diff=eval_neigh(neigh[i],(tp+1)%2);
            score.push_back(diff);
        }
        if(tp==0){
            int max=score[0];
            for(int j=1;j<score.size();j++){
                if(max<score[j]){max=score[j];}
            }
            return max;
        }
        else{
            int min=score[0];
            for(int j=1;j<score.size();j++){
                if(min>score[j]){min=score[j];}
            }
            return min;
        }
    }
}
//start of min - max
node start(node obj){
    vector<node> neigh=generate_neigh(obj,0);
    if(neigh.size()==1){
        return neigh[0];
    }
    else{
        vector<int> score;
        for(int i=0;i<neigh.size();i++){
            score.push_back(eval_neigh(neigh[i],1));
        }
        int max=score[0];
        int max_pos=0;
        for(int j=1;j<score.size();j++){
            if(max<score[j]){
                max=score[j];
                max_pos=j;
            }
        }
        return neigh[max_pos];
    }
}
int all_complete(node obj){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(obj.arr[i][j]==-1){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int arr[3][3]={{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
    node obj(arr);
    while(true){
        if(all_complete(obj)==1){
          obj.print_node();
          cout<<"R : "<<obj.r_score<<endl;
          cout<<"B : "<<obj.b_score<<endl;
          cout<<endl;
          if(obj.r_score>obj.b_score){
              cout<<"---R WON---"<<endl;
            }
          else if(obj.r_score<obj.b_score){
            cout<<"---B WON---"<<endl;
          }
          else{
            cout<<"---MATCH DRAWN---"<<endl;
          }
          break;
        }
        else{
            obj.print_node();
            cout<<"enter r and c"<<endl;
            int r,c;
            cin>>r>>c;
            cout<<endl;
            if(r>2||r<0||c<0||c>2){
                cout<<"--wrong r or c value--"<<endl<<endl;
            }
            else{
            if(obj.arr[r][c]==-1){
            obj.arr[r][c]=1;
            int b=analyze_board(obj,r,c,1);
            obj.b_score+=b;
            if(all_complete(obj)!=1){
            node my_ch=start(obj);
            for(int i1=0;i1<3;i1++){
              for(int j1=0;j1<3;j1++){
                if(obj.arr[i1][j1]!=my_ch.arr[i1][j1]){
                  obj.arr[i1][j1]=0;
                  int sc=analyze_board(obj,i1,j1,0);
                  obj.r_score+=sc;
                  break;
                }
              }
            }
            }
        }
        else{
            cout<<"r c --is occupied"<<endl;
        }
            }
        }
        
    }
}