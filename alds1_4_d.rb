n, k = gets.chomp.split.map(&:to_i)
w = [] * n
n.times do
  w << gets.chomp.to_i
end
tracks = Array.new(k, 0)
