def insertion_sort(a, n, g)
  cnt = 0

  g.upto(n - 1) do |i|
    v = a[i]
    j = i - g
    while j >= 0 && a[j] > v
      a[j + g] = a[j]
      j = j - g
      cnt += 1
      a[j + g] = v
    end
  end

  cnt
end

def shell_sort(a, n)
  g = [1]
  m = 1
  while (v = 3 * g[-1] + 1) <= n
    m += 1
    g << v
  end
  g.reverse!
  puts m
  puts g.map(&:to_s).join(' ')

  cnt = 0
  g.each do |gi|
    cnt += insertion_sort(a, n, gi)
  end
  puts cnt

  n.times do |i|
    puts a[i]
  end
end

n = gets.chomp.to_i
a = []
n.times do
  a << gets.chomp.to_i
end

shell_sort(a, n)