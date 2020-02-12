n = gets.chomp.to_i
a = []

n.times do
  a << gets.chomp.to_i
end

min = a[0]
a.shift

ans = -0xffffffff
a.each do |ai|
    ans = [ans, ai - min].max
    min = [min, ai].min
end
puts ans
