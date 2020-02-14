n, q = gets.chomp.split.map(&:to_i)
p = [] * n
h = Hash.new(0)
n.times do
  l = gets.chomp.split
  p << [l[0], l[1].to_i]
end

ela = 0
while !p.empty?
  p_name, time = p.shift

  change = [time, q].min
  ela += change

  if change == time
    h[p_name] = ela
  else
    p << [p_name, time - q]
  end
end
h.keys.each{|key| puts "#{key} #{h[key]}"}