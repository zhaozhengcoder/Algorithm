bool canJump(vector<int> & vi) {
	if (vi.size() == 1) {   //边界情况
		return false;
	}
	//isjump 表示对应下标的元素 是否可以跳到终点
	int size = vi.size();
	vector<bool> isjump (size,false);

	//从数组的倒数第二个元素向前更新
	for (int i = vi.size() - 2; i >= 0; i--) {
		int step_length = vi[i];
		//可以跳到终点
		if (step_length + i >= vi.size() - 1) {
			isjump[i] = true;
		}
		else {
			//可以跳到其他连通的点上面
			for (int j = 1; j <= step_length; j++) {
				if (isjump[i + j] == true) {
					isjump[i] = true;
				}
			}
		}
	}
	return isjump[0];
}