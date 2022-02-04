#include<bits/stdc++.h>
using namespace std;
bool srt(const string &a,const string &b){
	return a.size()<b.size();
}
vector <string> ans;
int argvl=10,argvg=5;
void solve(vector <string> v1,string last,int count){
	for(int i=0;i<v1.size();i++){
		string tmp=last+v1[i];
		if(tmp.size()<=argvl && count<=argvg)	
			ans.push_back(tmp);
		else
			return;
		string temp=v1[i];
		v1.erase(v1.begin()+i);
		if(v1.size()!=0)
			solve(v1,last+temp,count+1);
		else
			return;
		v1.push_back(temp);
		sort(v1.begin(),v1.end());
	}
	return;
}

int32_t main(int argc,char *argv_temp[]){
	vector <string> v1;
	if(argc==1){
		int n;cin>>n;
		for(int i=0;i<n;i++){
			string s;cin>>s;
			v1.push_back(s);
		}
	}else{
		for(int i=0;i<argc;i++)
			v1.push_back(argv_temp[i]);
		vector<string>::iterator it;
		it=find(v1.begin(), v1.end(), "-g");
		if(it!=v1.end()){
			string argv_g=*(it+1);
			argvg=0;
			for(auto i:argv_g)
				argvg=((10*argvg)+(i-48));
			v1.erase(v1.begin()+(it-v1.begin()));
			v1.erase(v1.begin()+(it-v1.begin()));
			argc-=2;
		}
		it=find(v1.begin(), v1.end(), "-l");
		if(it!=v1.end()){
			string argv_l=*(it+1);
			argvl=0;
			for(auto i:argv_l)
				argvl=((10*argvl)+(i-48));
			v1.erase(v1.begin()+(it-v1.begin()));
			v1.erase(v1.begin()+(it-v1.begin()));
			argc-=2;
		}	
		v1.erase(v1.begin());
	}
	sort(v1.begin(),v1.end());
	solve(v1,"",1);
	sort(ans.begin(),ans.end(),srt);
	string before="";
	for(auto i:ans){
		if(i.size()>=6 && i!=before)
			cout<<i<<"\n";
		before=i;
	}
	
}
