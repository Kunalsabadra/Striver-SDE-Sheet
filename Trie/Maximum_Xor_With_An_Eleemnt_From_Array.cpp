

class Node{
	public:

	Node* links[2];
};
class Trie{
	public:

	Node* root;
	Trie(){
		root=new Node();
	}
	void insert(int num){
		Node* node=root;
		for(int i=31; i>=0; i--){
			int bit=(num>>i)&1;
			if(!node->links[bit]){
				node->links[bit]=new Node();
			}
			node=node->links[bit];
		}
	}
	int maxnum(int num){
		int maxi=0;
		Node* node=root;
		for(int i=31; i>=0; i--){
			int bit=(num>>i)&1;
			if(node->links[1-bit]){
				maxi=maxi|(1<<i);
				node=node->links[1-bit];
			}
			else{
				node=node->links[bit];
			}
		}
		return maxi;
	}
};

	vector<int> maxXorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		Trie trie;
		sort(arr.begin(), arr.end());
		vector<pair<int, pair<int, int>>>v;
		for(int i=0; i<queries.size(); i++){
			v.push_back({queries[i][1], {queries[i][0], i}});
		}
		sort(v.begin(), v.end());
		vector<int>v1(queries.size(), 0);
		int st=0, en=arr.size();
		for(int i=0; i<queries.size(); i++){
			while(st<en && arr[st]<=v[i].first){
				trie.insert(arr[st]);
				st++;
			}
			if(st==0){v1[v[i].second.second]=-1;}
			else{v1[v[i].second.second]=trie.maxnum(v[i].second.first);}
		}
		return v1;
	}
