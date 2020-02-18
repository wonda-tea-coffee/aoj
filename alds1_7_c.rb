def pre_order(id)
  return if id == -1

  left, right = @nodes[id]

  [id, pre_order(left), pre_order(right)].flatten.compact
end

def in_order(id)
  return if id == -1

  left, right = @nodes[id]

  [in_order(left), id, in_order(right)].flatten.compact
end

def post_order(id)
  return if id == -1

  left, right = @nodes[id]

  [post_order(left), post_order(right), id].flatten.compact
end

def find_root
  @nodes.keys.each do |k|
    if !@parents[k]
      return k
    end
  end

  raise
end

@n = gets.chomp.to_i
@nodes = Hash.new{|k, v| k[v] = []}
@parents = {}
@n.times do
  id, left, right = gets.chomp.split.map(&:to_i)

  @nodes[id] << left
  @parents[left] = id

  @nodes[id] << right
  @parents[right] = id
end

puts "Preorder"
puts " #{pre_order(find_root).map(&:to_s).join(' ')}"

puts "Inorder"
puts " #{in_order(find_root).map(&:to_s).join(' ')}"

puts "Postorder"
puts " #{post_order(find_root).map(&:to_s).join(' ')}"
