#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <set>
#include <functional>
#include <time.h>
#include <Windows.h>
using namespace std;


string GetRandomString(const int len) {
	string str2(len+1,'\0');
	int i;
	for (i = 0; i<len; ++i)
		str2[i] = 'A' + rand() % 26;
	str2[++i] = '\0';
	return str2;
}




class Weibo {
public:
	int id;
	int uid;
	string text;
	int status;
	Weibo() {
		id = -1;
		uid = -1;
		text = "";
		status = -1;
	}


	static Weibo create(int _uid,string _text,int _status=0) {
		static int Self_growth_id = 0;

		Weibo w;
		w.id = Self_growth_id++;
		w.uid = _uid;
		w.text = _text;
		w.status = _status;
		return w;
	}
};



class Index_uid {
public:
	int HashID;
	int uid;
	set<Weibo *> set_pw;

	Index_uid() { HashID = -1; uid = -1; }
};

Index_uid empty_uid;

class Mysql_Weibo{
private:
	vector<Weibo> vw;
	vector<Index_uid> index_uid;
	bool index_uid_enable;
	hash<int> hash_int;
	int Maxuser;
public:
	Mysql_Weibo():vw(15000),index_uid(2000, empty_uid) {
		index_uid_enable = false;
		Maxuser = 2000;
	}
	//发布weibo
	void PostWeibo(int _uid,string _text) {
		Weibo w=Weibo::create(_uid, _text);
		vw.push_back(w);
	}

	//获得某个用户最近发布的十条weibo
	vector<Weibo> getTimeline(int user_id) {
		// Write your code here
		vector<Weibo> tl;
		int number = 10;
		for (auto it = vw.rbegin(); it != vw.rend() && number >= 0; it++) {
			if (it->uid == user_id) {
				number--;
				tl.push_back(*it);
			}
		}
		return tl;
	}

	//给uid上创建hash索引
	void CreateHashIndex_InUid(){
		
		index_uid.reserve(Maxuser);
		

		for (auto it = vw.begin(); it != vw.end(); it++) {
			int temp_uid = it->uid;
			int hash_uid=hash_int(temp_uid) %Maxuser;

			index_uid[hash_uid].uid = temp_uid;
			index_uid[hash_uid].HashID = hash_uid;
			index_uid[hash_uid].set_pw.insert(&(*it));
		}

		this->index_uid_enable = true;
	}

	//使用索引来查询uid的weibo
	vector<Weibo*> UseIndexQuery_inUid(int user_id) {
		vector<Weibo *> query_res;
		int hashid = hash_int(user_id)%Maxuser;
		auto it_begin = this->index_uid[hashid].set_pw.begin();
		auto it_end = this->index_uid[hashid].set_pw.end();

		for (auto it = this->index_uid[hashid].set_pw.begin(); it != this->index_uid[hashid].set_pw.end(); it++) {
			if ((*it)->uid == user_id) {
				query_res.push_back((*it));
			}
		}
		return query_res;
	}
};

void Print_Weibo(vector<Weibo> w) {
	cout << " >>> " << endl;
	for (auto it = w.begin(); it != w.end(); it++) {
		cout << "id : " << it-> id << "   userid : " << it->uid << "   text : " << it->text << "   status : " << it->status << endl;
	}
}

void Print_Weibo(vector<Weibo*> w) {
	cout << " >>> " << endl;
	for (auto it = w.begin(); it != w.end(); it++) {
		cout << "id : " << (*it)->id << "   userid : " << (*it)->uid << "   text : " << (*it)->text << "   status : " << (*it)->status << endl;
	}
}

void GetLocalTime() {
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << "Hour : " << sys.wHour << " , Minute : " << sys.wMinute << " ,second :" << sys.wSecond << " , millseconds :" << sys.wMilliseconds << endl;
}
int main() {
	Mysql_Weibo mysql_weibo;
	random_device rd;
	uniform_int_distribution<int> dist1(0, 500);
	uniform_int_distribution<int> dist2(1, 20);





	//假设有1w条weibo 和 500位用户
	for (int i = 0; i < 10000; i++) {
		int uid = dist1(rd);
		int str_len = dist2(rd);
		string text = GetRandomString(str_len);
		cout << text << endl;
		mysql_weibo.PostWeibo(uid,text);
	}
	
	int query_uid1 = 100;
	int query_uid2 = 120;
	int query_uid3 = 150;
	int query_uid4 = 200;
	int query_uid5 = 250;

	vector<Weibo> ret_wb1=mysql_weibo.getTimeline(query_uid1);
	vector<Weibo> ret_wb2 = mysql_weibo.getTimeline(query_uid2);
	vector<Weibo> ret_wb3 = mysql_weibo.getTimeline(query_uid3);
	vector<Weibo> ret_wb4 = mysql_weibo.getTimeline(query_uid4);
	vector<Weibo> ret_wb5= mysql_weibo.getTimeline(query_uid5);
	
	


	Print_Weibo(ret_wb1);
	//Print_Weibo(ret_wb2);
	//Print_Weibo(ret_wb3);
	//Print_Weibo(ret_wb4);
	//Print_Weibo(ret_wb5);

	mysql_weibo.CreateHashIndex_InUid();

	//mysql_weibo.UseIndexQuery_inUid(query_uid1);
	//mysql_weibo.UseIndexQuery_inUid(query_uid2);
	//mysql_weibo.UseIndexQuery_inUid(query_uid3);
	//mysql_weibo.UseIndexQuery_inUid(query_uid4);
	//mysql_weibo.UseIndexQuery_inUid(query_uid5);
	vector<Weibo*> ret_index_wb1=mysql_weibo.UseIndexQuery_inUid(query_uid1);
	vector<Weibo*> ret_index_wb2=mysql_weibo.UseIndexQuery_inUid(query_uid2);
	vector<Weibo*> ret_index_wb3=mysql_weibo.UseIndexQuery_inUid(query_uid3);
	vector<Weibo*> ret_index_wb4 = mysql_weibo.UseIndexQuery_inUid(query_uid4);
	vector<Weibo*> ret_index_wb5 = mysql_weibo.UseIndexQuery_inUid(query_uid5);


	Print_Weibo(ret_index_wb1);
	//Print_Weibo(ret_index_wb2);
	//Print_Weibo(ret_index_wb3);
	//Print_Weibo(ret_index_wb4);
	//Print_Weibo(ret_index_wb5);


	system("pause");
	return 0;
}
