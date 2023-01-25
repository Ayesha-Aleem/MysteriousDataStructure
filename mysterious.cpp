#include <iostream>
#include<fstream>
#include <sstream>
using namespace std;
bool stackR(string ar1[],string ar2[]);
bool queue(string ar1[],string ar2[]);
bool pq(string ar1[],string ar2[]);
char readFile();
int c1=0,c11=0,c12=0,c13=0,c2=0;
int solve( string myString) {
    int x;
    stringstream ss( myString );
    ss >> x;
    return x;
}
char writefile(){
    ofstream wr("inputfile.txt");
    wr<<6<<"\n";
    wr<<"push 1\n";
    wr<<"push 2\n";
    wr<<"push 3\n";
    wr<<"pop 3\n";
    wr<<"pop 2\n";
    wr<<"pop 1\n";
    wr.close();
    return 0;
}

bool stackR(string ar1[],string ar2[]){
    int s=0,h=c1-1,w=0;
    for(int i=0;i<h;i++) {
        if(ar1[h-i]==ar2[w]){
            s++;
            w++;
            c11=c11+1;
        }
        else if(solve(ar1[i])==0 || solve(ar1[w])==0 ) {
            cout<<" ";
            return 0;
        }
        else {
            c11=0;
            return 0;
        }
    }
}
bool queue(string ar1[],string ar2[]){
    int m=c2;
    for(int i=0;i<m;i++) {
        if(ar1[i]==ar2[i]){
            c12++;
        }
        else if(solve(ar1[i])==0 || solve(ar2[i])==0){
            cout<<" ";
        }
        else {
            c12=0;
            return 0;
        }
    }
}
bool pq(string ar1[],string ar2[]){
    int max=solve(ar1[0]),in=0;
    string va[c1];
    string text;
    for(int i=1;i<c1;i++){
        if(max<solve(ar1[i]) && solve(ar1[i])!=0) {
            text=ar1[i];
            max = solve(ar1[i]);
            va[in]=text[0];
            in++;
        }
        else if(solve(ar1[i])==0){
            cout<<" ";
        }
        else {
            cout<<" ";
        }

    }
    
    for(int j=0;j<in;j++){
            if(solve(ar2[j])==solve(va[in-1])){
                c13 = c13 + 1;
                in--;
            }
            else {
                c13=0;
            }
    }
        }



int main(int argc,char *argv[]) {
        //reading integer
    ifstream read(argv[1]);
        int num;
        read>>num;
        string arr1[num],arr2[num];
        string text;
        int ind=0,ind2=0,c=0;
        if(getline(read,text) && read.is_open()) {
            while (getline(read,text)) {
                if (text == "\n" || text=="") {
                    c++;
                }
                else if (text.length()>=6 && text.length()<=8) {
                    arr1[ind]=text[5];
                    ind++;
                    c1=c1+1;
                }
                else if (text.length()>=5 && text.length()<=8  ) {
                    arr2[ind2]=text[4];
                    ind2++;
                    c2=c2+1;
                }
                else {
                    cout << " ";
                }
            }
        }
        else {
            cout<<"Impossible\n";
            return 0;
        }
        stackR(arr1,arr2);
        queue(arr1,arr2);
        pq(arr1,arr2);
        if(c11>0 && c12==0 && c13==0){
            cout<<"LIFO";
        }
        else if(c12>0 && c11==0 && c13==0){
            cout<<"FIFO";
        }
        else if(c13>0 && c12==0 && c11==0){
            cout<<"PQ";
        }
        else if(c11>0 || c12>0 || c13>0){
            cout<<"NOT SURE";
        }
        else {
            cout<<"IMPOSSIBLE";
        }
        return 0;

}
