n = gets.chomp.to_i
dp = [] * (n + 1)

dp[0] = 1
dp[1] = 1 if n >= 1
2.upto(n) do |i|
  dp[i] = dp[i-1] + dp[i-2]
end

puts dp[n]