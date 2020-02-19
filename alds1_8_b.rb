class BinaryTree
  attr_accessor :key, :left, :right, :parent

  def initialize(key, left, right, parent)
    @key    = key.to_i
    @left   = left
    @right  = right
    @parent = parent
  end

  def root
    if parent
      parent.root
    else
      self
    end
  end

  def insert(z)
    x = root
    y = nil

    while x
      y = x
      if z.key < x.key
        x = x.left
      else
        x = x.right
      end
    end

    z.parent = y
    if y.nil?
      key = z.key
      left = z.left
      right = z.right
    elsif z.key < y.key
      y.left = z
    else
      y.right = z
    end
  end

  def find(k)
    k = k.to_i

    if k < key
      !!left&.find(k)
    elsif k > key
      !!right&.find(k)
    else
      k == key
    end
  end

  def show
    in_order
    puts "\n"
    pre_order
    puts "\n"
  end

  def in_order
    left&.in_order
    print " #{key}"
    right&.in_order
  end

  def pre_order
    print " #{key}"
    left&.pre_order
    right&.pre_order
  end
end

n = gets.chomp.to_i
bt = nil
n.times do
  op, key = gets.chomp.split

  case op
  when 'insert'
    if bt
      bt.insert(BinaryTree.new(key, nil, nil, nil))
    else
      bt = BinaryTree.new(key, nil, nil, nil)
    end
  when 'find'
    puts bt.find(key) ? 'yes' : 'no'
  when 'print'
    bt.show
  end
end