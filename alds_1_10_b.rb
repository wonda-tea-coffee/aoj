n = gets.to_i
m = [] * n
n.times do
  m << gets.chomp.split.map(&:to_i)
end

INF = 0xffffffff
dp = Array.new(n) { Array.new(n, INF) }

# i < j のみ考える（＝四角形の右上半分、対角線も除く）
# dp[0][1], dp[1][2], ..., dp[n-2][n-1] は m[i][0]


ans = INF
1.upto(n - 2) do |i|
  ans = [ans, dp[0][i] + dp[i + 1][n - 1] + m[0][1]].min
end
puts ans