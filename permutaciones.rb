def swapear(array, index1, index2)
  res = array.dup
  res[index1] , res[index2] = res[index2], res[index1]
  res
end

def estanTodas?(vistos, premutaciones)
  vistos.any? { |v| not premutaciones.include? v }
end

def dame_perm(permutame=[1,2,3,4], vistos=[[1,2,3,4]], profundidad=0)
  puts nil
  puts profundidad
  puts nil
  puts "#{permutame}"
  puts nil
  nuevoPermutame = []
  permutame.each_index do |i|
    permutame.each_index do |ii|
      if ii > i
        swapeado = swapear(permutame, i, ii)
        if vistos.include? swapeado
          puts "#{swapeado} x"
        else
          vistos << swapeado.dup
          nuevoPermutame = swapeado.dup
          puts "#{swapeado}"
        end
      end
    end
  end
  dame_perm(nuevoPermutame, vistos, profundidad+1) unless estanTodas?(vistos, permutame.permutation.to_a)
end