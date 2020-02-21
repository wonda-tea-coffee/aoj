def lcs(x, y)
  m = x.size
  n = y.size
  dp = Array.new(m + 1) { Array.new(n + 1, 0) }

  1.upto(m) do |i|
    1.upto(n) do |j|
      if x[i - 1] == y[j - 1]
        dp[i][j] = dp[i - 1][j - 1] + 1
      else
        dp[i][j] = [dp[i - 1][j], dp[i][j - 1]].max
      end
    end
  end

  dp[m][n]
end

gets.to_i.times do
  x = gets.chomp.chars
  y = gets.chomp.chars
  puts lcs(x, y)
end
