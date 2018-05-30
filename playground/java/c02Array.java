class c02Array {
	public static void main(String args[]) {
		int arr[][] = new int[2][5];
		int d1[] = new int[10];
		arr[1] = d1;
		
		d1[9] = 12;
		System.out.println(arr[1][9]);  // 12
		System.out.println(arr[0][9]);  // 下标越界错误
	}
}
