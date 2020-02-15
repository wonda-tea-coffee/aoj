def dfs(n, a, i, sum)
  @h[sum] = true

  return if i == n

  dfs(n, a, i + 1, sum)
  dfs(n, a, i + 1, sum + a[i])
end

n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
q = gets.chomp.to_i
m = gets.chomp.split.map(&:to_i)

@h = Hash.new(false)
dfs(n, a, 0, 0)

m.each do |mi|
  puts @h[mi] ? 'yes' : 'no'
end
