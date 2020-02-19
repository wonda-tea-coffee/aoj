class Node
  def initialize(val)
    @val = val
    @left = nil
    @right = nil
  end

  def insert(val)
    if val < @val
      if @left
        @left.insert(val)
      else
        @left = Node.new(val)
      end
    else
      if @right
        @right.insert(val)
      else
        @right = Node.new(val)
      end
    end
  end

  def print
    puts " #{inorder([]).join(" ")}"
    puts " #{preorder([]).join(" ")}"
  end

  def preorder(list)
    #root
    list << @val
    #left
    list = @left.preorder(list) if @left
    #right
    list = @right.preorder(list) if @right
    list
  end

  def inorder(list)
    #left
    list = @left.inorder(list) if @left
    #root
    list << @val
    #right
    list = @right.inorder(list) if @right
    list
  end

  def find(num)
    if @val == num
      "yes"
    elsif @val > num
      if @left
        @left.find(num)
      else
        "no"
      end
    else
      if @right
        @right.find(num)
      else
        "no"
      end
    end
  end

  def del(num)
    if @val == num
      # delete
      if @left && @right
        @val = @right.next_val
        @right = @right.del(@val)
        self
      elsif @left && @right.nil?
        @left
      elsif @left.nil? && @right
        @right
      end
    elsif @val > num
      @left = @left.del(num) if @left
      self
    else
      @right = @right.del(num) if @right
      self
    end
  end

  def next_val
    @left ? @left.next_val : @val
  end
end

n = gets.to_i
tree = nil

n.times do
  command, num = gets.split
  case command
  when "insert"
    if tree
      tree.insert(num.to_i)
    else
      tree = Node.new(num.to_i)
    end
  when "find"
    puts tree.find(num.to_i)
  when "delete"
    tree = tree.del(num.to_i)
  when "print"
    tree.print
  end
end
