n = gets.chomp.to_i
h = {}
n.times do
  op, key = gets.chomp.split
  if op == 'insert'
    h[key] = 1
  else
    puts h[key] ? 'yes' : 'no'
  end
end