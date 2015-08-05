/*************************************************************************
  > File Name: hanoi.cpp
  > Author: ma6174
  > Mail: ma6174@163.com 
  > Created Time: 2015年08月05日 星期三 15时32分22秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

struct op{
	int begin;
	int end;
	char src;
	char bri;
	char dst;
	op(){}
	op(int pbegin,int pend,char psrc,char pbri,char pdst):begin(pbegin),end(pend),src(psrc),bri(pbri),dst(pdst){}
};
void hanoi(int n,char src,char bri,char dst){
	stack<op> st;
	op tmp;
	st.push(op(1,n,src,bri,dst));

	while(!st.empty()){
		tmp = st.top();
		st.pop();
		if(tmp.begin != tmp.end){
			st.push(op(tmp.begin,tmp.end-1,tmp.bri,tmp.src,tmp.dst));
			st.push(op(tmp.end,tmp.end,tmp.src,tmp.bri,tmp.dst));
			st.push(op(tmp.begin,tmp.end-1,tmp.src,tmp.dst,tmp.bri));
		}
		else{
			cout<<"move "<<tmp.end<<"from "<<tmp.src<<"to "<<tmp.dst<<endl;
		}
	}
}

void hanoiWithRecursion(int begin,int end,char src,char bri,char dst){
	if(begin == end)
		cout<<"move "<<end<<"from "<<src<<"to "<<dst<<endl;
	else{
		hanoiWithRecursion(begin,end -1, src,dst,bri);
		hanoiWithRecursion(end,end, src,bri,dst);
		hanoiWithRecursion(begin,end -1, bri,src,dst);
	}
}
int main(){
	hanoiWithRecursion(1,15,'A','B','C');
}
