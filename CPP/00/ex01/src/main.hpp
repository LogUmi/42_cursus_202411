/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:50:09 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/30 20:14:49 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

int			get_str(std::string &input, std::string str);
int			get_int(int *input, std::string str);
int			is_name(std::string str);
int			is_printable(std::string str);
int			is_digit(std::string str);
std::string	int_to_string(int val);

#endif