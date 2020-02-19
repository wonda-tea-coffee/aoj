def parent_key(nodes, i)
  return if i < 2

  nodes[i / 2]
end

def left_key(nodes, i)
  nodes[i * 2]
end

def right_key(nodes, i)
  nodes[i * 2 + 1]
end

H = gets.chomp.to_i
keys = gets.chomp.split.map(&:to_i)
nodes = {}
keys.each.with_index(1) do |key, i|
  nodes[i] = key
end

nodes.each do |k, v|
  print "node #{k}: "
  print "key = #{v}, "
  print "parent key = #{parent_key(nodes, k)}, " if parent_key(nodes, k)
  print "left key = #{left_key(nodes, k)}, "     if left_key(nodes, k)
  print "right key = #{right_key(nodes, k)}, "   if right_key(nodes, k)
  puts "\n"
end
