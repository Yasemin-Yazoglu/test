#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <type_traits>

template<typename T, std::size_t N, std::size_t M>

class Matrix {
    private:
        std::array<std::array<T, M>, N> data;

    public:
        Matrix() : data{} {}

        void print() const {
            for (const auto& row : data)  {
                for (const auto& element : row) {
                    std::cout << element << ' ';    
                }
                std::cout << '\n';
            }
        }

        T& get(std::size_t i, std::size_t j) {
            return data[i][j];
        }

        const T& get(std::size_t i, std::size_t j) const {
            return data[i][j];
        }

        Matrix<T, M, N> transpose() const {
            Matrix<T, M, N> result;
            for(std::size_t i = 0; i < N; ++i) {
                for (std::size_t j = 0; j < M; ++j) {
                    result.get(j, i) = this->get(i, j);
                }
            }
            return result;
        }

        Matrix<T, N, M> add(const Matrix<T, N, M>& other) const {
            Matrix<T, N, M> result;
            for (std::size_t i = 0; i < N; ++i) {
                for (std::size_t j = 0; j < M; ++j) {
                    result.get(i, j) = this->get(i, j) + other.get(i, j);
                }
            }

            return result;
        }

        Matrix<T, N, M> subtract(const Matrix<T, N, M>& other) const {
            Matrix<T, N, M> result;
            for (std::size_t i = 0; i < N; ++i) {
                for (std::size_t j = 0; j < M; ++j) {
                    result.get(i, j) = this->get(i, j) - other.get(i, j);
                }
            }
            return result;
        }


        template <std::size_t P>
        Matrix<T, N, P> multiply(const Matrix<T, M, P>& other) const {
            Matrix<T, N, P> result;
            for (std::size_t i = 0; i < N; ++i) {
                for (std::size_t j = 0; j < P; ++j) {
                    result.get(i, j) = 0;
                    for (std::size_t k = 0; k < M; ++k) {
                        result.get(i, j) += this->get(i, k) * other.get(k, j);
                    }
                }
            }
            return result;
        }
        
        template <typename Container>
        Matrix(const Container& container) {
            if (container.size() != N) {
                throw std::invalid_argument("Container size must match matrix size");
            }

            for (std::size_t i = 0; i < N; ++i) {
                if (container[i].size() != M) {
                    throw std::invalid_argument("Container inner size must match matrix size");
                }

                for (std::size_t j = 0; j < M; ++j) {
                    this->get(i, j) = container[i][j];
                }
            }
        }
};
