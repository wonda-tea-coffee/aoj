def type(id)
  if @parents[id] == -1
    return 'root'
  end

  if @nodes[id].empty?
    'leaf'
  else
    'internal node'
  end
end

def set_depth(id, depth)
  @depths[id] = depth

  @nodes[id].each do |node|
    set_depth(node, depth + 1)
  end
end

def find_root_id
  @nodes.keys.each do |key|
    return key if @parents[key] == -1
  end

  raise
end

def set_height(id)
  if @nodes[id].empty?
    @heights[id] = 0
    return
  end

  max_height = 0
  @nodes[id].each do |_id|
    set_height(_id)
    max_height = [max_height, @heights[_id]].max
  end

  @heights[id] = max_height + 1
end

@n = gets.chomp.to_i
@nodes = Hash.new{|k, v| k[v] = []}
@parents = Hash.new(-1)
siblings = Hash.new(-1)
@heights = Hash.new(0)
@depths = {}

@n.times do
  id, left, right = gets.chomp.split.map(&:to_i)
  @nodes[id] = []

  if left != -1
    @nodes[id] << left
    @parents[left] = id
    siblings[left] = right
  end

  if right != -1
    @nodes[id] << right
    @parents[right] = id
    siblings[right] = left
  end
end

set_depth(find_root_id, 0)

set_height(find_root_id)

@nodes.keys.sort.each do |id|
  puts "node #{id}: parent = #{@parents[id]}, sibling = #{siblings[id]}, degree = #{@nodes[id].size}, depth = #{@depths[id]}, height = #{@heights[id]}, #{type(id)}"
end