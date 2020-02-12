n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)

puts a.map(&:to_s).join(' ')

1.upto(n - 1) do |i|
  v = a[i]
  j = i - 1
  while j >= 0 && a[j] > v
    a[j + 1] = a[j]
    j -= 1
  end
  a[j + 1] = v

  puts a.map(&:to_s).join(' ')
end
