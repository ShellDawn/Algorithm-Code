package main

import "fmt"

func main(){
	nums := []int{0,1,2,3,4}
	index := []int{0,1,2,2,1}
	fmt.Println(createTargetArray(nums,index))
}

func createTargetArray(nums []int, index []int) []int {
	L := len(index)
	for i:=0;i<L;i++{
		for j:=i+1;j<L;j++{
			if index[j] <= index[i]{
				index[i]++
			}
		}
	}
	ans := make([]int,L)
	for i:=0;i<L;i++{
		ans[index[i]] = nums[i]
	}
	return ans
}