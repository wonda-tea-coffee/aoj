def stable?(in_arr, out_arr)
  n = in_arr.size

  0.upto(n - 1) do |i|
    (i + 1).upto(n - 1) do |j|
      next unless eq?(in_arr[i], in_arr[j])

      0.upto(n - 1) do |a|
        (a + 1).upto(n - 1) do |b|
          if in_arr[i] == out_arr[b] && in_arr[j] == out_arr[a]
            # puts "i = #{i}, j = #{j}, a = #{a}, b = #{b}"
            return false
          end
        end
      end
    end
  end

  true
end

def eq?(a, b)
  a = a[-1].to_i
  b = b[-1].to_i

  a == b
end

def compare(a, b)
  a = a[-1].to_i
  b = b[-1].to_i

  a > b
end

def bubble_sort(n, a)
  ret = a.dup
  n.times do |i|
    j = n - 1
    while j > i
      if compare(ret[j - 1], ret[j])
        tmp = ret[j]
        ret[j] = ret[j - 1]
        ret[j - 1] = tmp
      end
      j -= 1
    end
  end
  ret
end

def selection_sort(n, a)
  ret = a.dup
  0.upto(n - 1) do |i|
    minj = i
    i.upto(n - 1) do |j|
      if compare(ret[minj], ret[j])
        minj = j
      end
    end

    if i != minj
      tmp = ret[i]
      ret[i] = ret[minj]
      ret[minj] = tmp
    end
  end
  ret
end

n = gets.chomp.to_i
a = gets.chomp.split

b = bubble_sort(n, a)
puts b.join(' ')
puts stable?(a, b) ? 'Stable' : 'Not stable'

s = selection_sort(n, a)
puts s.join(' ')
puts stable?(a, s) ? 'Stable' : 'Not stable'