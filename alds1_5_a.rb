n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
q = gets.chomp.to_i
m = gets.chomp.split.map(&:to_i)

h = {}

0.upto((1 << n) - 1) do |i|
  sum = 0
  0.upto(n - 1) do |j|
    if i & (1 << j) > 0
      sum += a[j]
    end
  end
  h[sum] = true
end

m.each do |mi|
  puts h[mi] ? 'yes' : 'no'
end
