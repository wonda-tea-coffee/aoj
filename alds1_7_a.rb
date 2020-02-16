def set_depth(id, depth)
  @depths[id] = depth

  @nodes[id].each do |child_id|
    set_depth(child_id, depth + 1)
  end
end

def root_id
  @nodes.each do |k, _|
    if @parents[k] == -1
      return k
    end
  end
end

def type(id)
  return 'root' if @parents[id] == -1
  return 'leaf' if @nodes[id].empty?
  'internal node'
end

n = gets.chomp.to_i
@nodes = Hash.new([])
@parents = Hash.new(-1)
@depths = {}
n.times do
  id, k, *c = gets.chomp.split.map(&:to_i)
  @nodes[id] = c
  c.each do |ci|
    @parents[ci] = id
  end
end
set_depth(root_id, 0)

@nodes.keys.sort.each do |k|
  puts "node #{k}: parent = #{@parents[k]}, depth = #{@depths[k]}, #{type(k)}, #{@nodes[k]}"
end