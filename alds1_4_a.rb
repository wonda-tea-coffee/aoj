N = gets.chomp.to_i
S = gets.chomp.split.map(&:to_i)
Q = gets.chomp.to_i
T = gets.chomp.split.map(&:to_i)

puts (S & T).size