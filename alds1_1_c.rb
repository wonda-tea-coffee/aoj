require 'prime'
n = gets.chomp.to_i
ans = 0
n.times do
  ni = gets.chomp.to_i
  ans += 1 if Prime.instance.prime?(ni)
end
puts ans