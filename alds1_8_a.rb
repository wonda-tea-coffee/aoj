class BinaryTree
  attr_accessor :key, :left, :right, :parent

  def initialize(key=nil, left=nil, right=nil, parent=nil)
    @key = key
    @left = left
    @right = right
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
    y = nil # x の親
    x = root
    while x
      y = x # 親を設定
      if z.key < x.key
        x = x.left # 左の子へ移動
      else
        x = x.right # 右の子へ移動
      end
    end
    z.parent = y

    if y.nil? # t が空の場合
      key = z.key
      left = z.left
      right = z.right
    elsif z.key < y.key
      y.left = z # z を y の左の子にする
    else
      y.right = z # z を y の右の子にする
    end
  end

  def in_order
    ret = []
    ret << left.in_order if left
    ret << key
    ret << right.in_order if right
    ret.flatten.compact
  end

  def pre_order
    ret = []
    ret << key
    ret << left.pre_order if left
    ret << right.pre_order if right
    ret.flatten.compact
  end
end

n = gets.chomp.to_i

bt = nil
n.times do
  op, x = gets.chomp.split

  if op == 'insert'
    if bt.nil?
      bt = BinaryTree.new(x.to_i, nil, nil, nil)
    else
      bt.insert(BinaryTree.new(x.to_i, nil, nil, nil))
    end
  else
    puts " #{bt.in_order.map(&:to_s).join(' ')}"
    puts " #{bt.pre_order.map(&:to_s).join(' ')}"
  end
end