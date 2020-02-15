n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
k = a.max
c = [0] * (k + 1)

a.each do |ai|
  c[ai] += 1
end
ans = []
c.each.with_index do |ci, i|
  ci.times do
    ans << i
  end
end
puts ans.map(&:to_s).join(' ')
