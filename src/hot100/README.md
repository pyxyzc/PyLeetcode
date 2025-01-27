| 题目                                                         | 记录                                                         | 星星 | 完成 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- | ---- |
| [1. 两数之和](https://leetcode.cn/problems/two-sum/)         | 经典哈希。Note：第一次写肯定是先全部哈希后找，其实每次找都「往回」看就行，这个「两数对」具有顺序的性质，所以按照一个方向「看一遍」是最好的，所以可以查找后更新，一次遍历即可。在这道题目中是没有意义的考虑，但是后边题目可能会有意想不到的作用。 | ⭐⭐⭐  | ✅    |
| [49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams/) | 经典哈希，关键是 key 用排序后的 str 来做（标准做法）。其实用什么都可以，比如 abc 写成 a1b1c1，只要没有哈希冲突，瞎写都可以。 | /    | ✅    |
| [128. 最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/) | 经典哈希，最大的作用是 for each 可以快速拿到可能的（key）值，接下来按照思路模拟，尽量拓宽连续的长度，向左扩展（查询 x-1 是否存在）向右扩展，即对每个「最左」的可能左边界尽量向右拓展。注意这里不用额外开 flag map 了，因为 for each + 向左扩展的判断条件就已经「过滤」了。 | ⭐⭐⭐  | ✅    |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |

| 题目                                                         | 记录                                                         | 星星 | 完成 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- | ---- |
| [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/) | 经典DP（有负数不能 sliding window），经典以结尾元素辅助定义，Why？能「拆」成更小规模的子问题。<br />另外一个很有趣的思路，前缀和后转成买卖股票问题，甚至可以只做一次遍历（前缀和随遍历维护即可）。子数组不能为空，因此应当先计算当前前缀和-历史小，再去更新历史小。 | ⭐⭐   | ✅    |
| [56. 合并区间](https://leetcode.cn/problems/merge-intervals/) | 经典区间合并，满足合并条件更新当前 ans.back() 右端点（取max），否则更新 ans。Note：开始的时候要特判 ans.empty()，或者直接循环前加上首个 interval。 | ⭐⭐⭐  | ✅    |
| [189. 轮转数组](https://leetcode.cn/problems/rotate-array/)  | 脑筋急转弯，三种算法。开新数组拷贝 new[(i + k) % n] = nums[i];。直接将每个数字放至它最后的位置，使用 temp 记录被替换的值，用 temp 做下一次「放置」，直至回到初始位置，问题是要做几次这个「循环」？答案是 gcd(k,n)，实现上的一个 trick：do {} while(start!=cur); 来从 start 开始。第三个思路：翻转数组，因为尾部 k mod n 个数的元素会往前「跑」，其余元素后移（直接从结果看），所以直接送到前面再翻转得到结果。 | /    | ✅    |
|                                                              | 发现周赛总喜欢出 lcm / gcd，还是再深究一下 「循环」次数的证明，非常简单的数论。「循环」次数 == 「环」的总个数。从 start 开始，每次跳到 (x+k) mod n，从起点到回到起点，设 a 是单次「循环」下的跳跃次数/访问到的元素数量，从起点第一次回到起点，即 min a（因为是首次）下的 $(i + ak) \equiv i \pmod{n} $ -> $ak \equiv 0 \pmod{n}$，也就是 ak == mn，且使得 min a，则 ak == lcm(k,n)。于是设 b 为「循环」次数，应该走几次整「环」？$b = \frac{n}{a} = \frac{n}{\frac{\text{lcm}(n, k)}{k}} = \frac{n \cdot k}{\text{lcm}(n, k)} = \gcd(n, k)$。 | /    | /    |
| [238. 除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/) | 脑筋急转弯，precompute 每个位置的「前积」和「后积」，位置 i 的答案即 i-1 的「前积」乘上 i+1 的「后积」，特判开头和结尾元素即可。维护上其实有点像「接雨水」的一种解法。 | /    | ✅    |
| [41. 缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive/) | O(N) 时间复杂度 + O(1) 空间复杂度，脑筋急转弯，经典原地哈希。从 start 开始，把其元素放在「该放置的位置」（即将数值为 i 的值放到下标为 i-1 的位置），接连进行置换，怎么找出来确实的第一个正数？抽屉原理，[1,nums.size()+1] 中必然存在解，则可以「排除」超出范围的数，让存在的数占上位置（重复数不用考虑），最后找第一个没占位置的数即可。Why 可行？以上的映射实际上就是「哈希」，同时我们可以确定解范围（和数组大小相同），所以原地做就可以。<br />Note：实现上，1映射0，nums.size()+1 映射 nums.size()，这是值排除的范围。如果全部满，意味着原数组的 nums.size() 个除了顺序乱之外，全部可以放到 [1,nums.size()] 中应该在的位置上（即我们并没有进行值范围排除/值重复排除），这时候返回nums.size()+1即可。 | ⭐    | ✅    |
| [73. 矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/) | 脑筋急转弯，直接的想法是开 O(n+m) 的两个数组记录每行每列是不是用置0。O(1) 的做法是，利用第一行第一列作为标志列（相当于前面标志数组的作用）来记录其他行/列是否置0，但是问题在于，第一行/列是否需要置0？可以额外用两个变量记录一下，于是总体还是 O(1) 空间复杂度。 | /    | ✅    |
| [54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)  | 经典模拟题，螺旋遍历的同时更新上下左右四个「边界」，l/r/t/b，什么时候结束？边界相遇。 | /    | ✅    |
| [48. 旋转图像](https://leetcode.cn/problems/rotate-image/)   | 经典模拟题，不以行/列为单位，而是以单元格为单位，四个值做 swap 记录一个 temp 即可。<br />Note：实现上，确定边界和（到底分不分奇偶讨论）是个问题，n 为偶数时候，好办，直接分成了四个区域，所以是 n/2 x n/2 的区域来做起始点转换，而奇数，保留中心，则是 (n-1)/2 x (n+1)/2 的区域，个人习惯在遍历前就定好 i 和 j 的上届（奇偶分类）。<br />另一种思路是一层一层由外向里遍历做旋转，也可以，个人不是很喜欢。 | /    | ✅    |
|                                                              |                                                              |      |      |
| [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/) | 脑筋急转弯，二分找每一行，mO(logn) ❎，Why？实际上只利用了一个特性，即左到右有序；从右上角开始找，直接使用每行最大元素/每列最小元素做排除，对应左到右有序（删除一行），上到下有序（删除一列），O(m+n) ✅。 | /    | ✅    |
| [160. 相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/) | O(1) 空间复杂度，基本限定只能遍历（双指针）做了。问题是如何「设计」遍历，让相遇的结果是相交节点，或者使得一个「标志」告诉我们不相交。一个巧妙的设计，使得指针在到达尾节点后（长度不一的相交链表，则两个指针必然不会同时到达），将其置于另一条链表的头节点处重新出发，则其会在可能的链表相交点处相遇。 | /    | ✅    |
| [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) | 递归/迭代解法，递归难理解一些，尽量把递归返还的结果当成子任务的结果，仅需要处理当前节点+子任务结果=总任务结果。迭代好写，建议使用。Note：迭代中的 pre 在本题中可以直接设置为 nullptr，如果反转链表作为其他题目的一部分，则需要考虑 pre 的具体值是什么，是否需要记录一开始的 pre 值。 | ⭐⭐⭐  | ✅    |
| [234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/) | 快慢指针找到中间节点后，反转后半部分链表，前后直接遍历比较。 | ⭐    | ✅    |
| [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/) | 经典快慢指针应用，判断是否有环。                             | /    | ✅    |
| [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/) | 进入环前的长度为a，环长为b。快慢指针相遇，2x-x=nb，x=nb，x=a+c（slow在环中走过的距离）=nb，c=nb-a。slow指针再走a，则到达入口。How 让slow走a步呢？我们并不知道a，答案是让fast回到head，同时走，则fast走a正好也到入口，两者相遇。 | /    | ✅    |
| [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) | 「链表」版分治算法的合并操作，一方「耗尽」后的操作更方便了，直接接上有剩余的另一方即可。dummy节点好用。 | /    | ✅    |
| [2. 两数相加](https://leetcode.cn/problems/add-two-numbers/) | 已经逆序了，直接                                             |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
| [46. 全排列](https://leetcode.cn/problems/permutations/)     | 排序，顺序 matters。                                         |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
| [39. 组合总和](https://leetcode.cn/problems/combination-sum/) | 回溯，可重复选取，选子集。「选」的过程直接去重，直接从当前index开始遍历（不考虑之前的选项）。<br />中间dfs仍然进入i层 <- 可重复选取。 | ⭐⭐⭐  | ✅    |
| [22. 括号生成](https://leetcode.cn/problems/generate-parentheses/) | 回溯，通过对左右括号的合法性判断（记录左右括号数量，保证<n且right<left），进入下一层dfs。由于i层必是选了j个左和i-j个右，因此不用传两个值，不过没必要，逻辑不清晰。 | ⭐    | ✅    |
| [79. 单词搜索](https://leetcode.cn/problems/word-search/)    | 二维回溯，选取「符合」节点开始dfs。                          | ⭐⭐   | ✅    |
| [131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning/) | 字串连续，从当前状态 -> 下一个状态，枚举可能的下一个状态，即可能的「回文子串」，枚举前后回溯。 | ⭐⭐⭐  | ✅    |
| [51. N 皇后](https://leetcode.cn/problems/n-queens/)         | 如何表示棋盘？固定行号下的列号全排列<br />check什么？行列满足要求，check斜方向，左上/右上（维护两个数组）<br /> |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
| [74. 搜索二维矩阵](https://leetcode.cn/problems/search-a-2d-matrix/) | 比[240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)，两次二分即可。 |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |
|                                                              |                                                              |      |      |

| 题目                                                         | 记录                                                         | 星星 | 完成 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- | ---- |
| [287. 寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number/) | 脑筋急转弯，强制要求 O(1) 空间复杂度，否则直接哈希了。（个人更喜欢）二分思路，在范围 [1,n-1]（假设 nums size 为 n）中做二分，「有序性」在于 [1,target-1] 中 <=i 的个数 <=i，[target,n-1] 中 <=i 的个数 >i。另一个思路，利用索引到值的映射一定存在不同索引映射到同一值（重复数），将映射看作链表，则重复数就是「环」的入口，快慢指针找即可。 | /    | ✅    |
| [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/) | 脑筋急转弯，二分找每一行，mO(logn) ❎，Why？实际上只利用了一个特性，即左到右有序；从右上角开始找，直接使用每行最大元素/每列最小元素做排除，对应左到右有序（删除一行），上到下有序（删除一列），O(m+n) ✅。 | /    | ✅    |
| [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | Note：无重复元素。利用先序和中序的特性，先序遍历提供子树的「root」，中序在拿到「root」后确定左右子树的 size（哈希）。实现上，建议别强求代码简洁性，把 left 和 right size 分别求出来，直接在 pre_root 和 in_root 上利用 size 做加减，好想一些。 | ⭐    | ✅    |
| [232. 用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks/) | 输入输出栈。                                                 | /    | ✅    |
| [509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number/) | /                                                            | /    | ✅    |
| [153. 寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/) | 经典二分，取第一个元素作为比较对象，前半段>=val，后半段<val，找后半段第一个。闭区间写法，考虑一个全升序特判（肯定存在找不到后半段的情况，left 直接越界了），不强求完全无特判的思路。 | ⭐    | ✅    |
| [191. 位1的个数](https://leetcode.cn/problems/number-of-1-bits/) | 位运算，复习一下位运算的经典操作。n & (1 << i)，检查32位，O(32)。n &= n - 1，每次把最低位的 1 变为 0，统计循环次数即可。或者直接 STL，bitset<32> a(n); return a.count();。 | ⭐    | ✅    |
| [50. Pow(x, n)](https://leetcode.cn/problems/powx-n/)        | 经典分治，快速幂。实现上，n=INT_MIN -> -n==-INT_MIN=INT_MAX+1，溢出，所以直接用long long。 | /    | ✅    |































