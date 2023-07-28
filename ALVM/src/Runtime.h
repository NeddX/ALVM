#ifndef ALVM_RUNTIME_H
#define ALVM_RUNTIME_H

#include <sdafx.h>

#include "Register.h"
#include "ByteBuffer.h"
#include "Instruction.h"

namespace rlang::alvm {
	constexpr int STACK_SIZE = 30;//1024 * 1024 * 2;

	class ALVM
	{
		using InstructionHandler = void(ALVM::*)();

	private:
		Instruction* m_Bytecode = nullptr;
		Instruction* m_Pc = nullptr;
		std::vector<std::uint8_t> m_Stack;
		Registers m_Registers;
		std::uintptr_t& m_Sp;
		const std::vector<InstructionHandler> m_Instructions =
		{
			&ALVM::End,
			&ALVM::Push,
			&ALVM::Pop,
			&ALVM::Add,
			&ALVM::Sub,
			&ALVM::Mul,
			&ALVM::Div,
			&ALVM::Increment,
			&ALVM::Decrement,
			&ALVM::PrintInt,
			&ALVM::PrintStr,
            &ALVM::Cmp,
			&ALVM::Move,
			&ALVM::Jump,
			&ALVM::ConditionalJump,
			&ALVM::ConditionalNotJump,
			&ALVM::Call,
			&ALVM::Return,
			&ALVM::Malloc,
			&ALVM::Free,
			&ALVM::Lrzf,
			&ALVM::Srzf,
			&ALVM::Store,
			&ALVM::Load,
			&ALVM::JmpIfZero,
			&ALVM::JmpIfNotZero,
			&ALVM::JmpIfNegative,
			&ALVM::JmpIfNotNegative,
			&ALVM::JmpIfOverflow,
			&ALVM::JmpIfNotOverflow,
			&ALVM::JmpIfCarry,
			&ALVM::JmpIfNotCarry,

			&ALVM::JmpIfSignedLessThan,
			&ALVM::Nop
	};
	public:
		ALVM(const std::vector<std::uint8_t>& data);

	public:
		void Run(const std::vector<Instruction>& code, std::int32_t& result);

	private:
		void End();
		void Push();
		void Pop();
		void Add();
		void Sub();
		void Mul();
		void Div();
		void Increment();
		void Decrement();
		void PrintInt();
		void PrintStr();
        void Cmp();
		void Move();
		void Jump();
		void ConditionalJump();
		void ConditionalNotJump();
		void Call();
		void Return();
		void Malloc();
		void Free();
		void Lrzf();
		void Srzf();
		void Store();
		void Load();
		void JmpIfZero();
		void JmpIfNotZero();
		void JmpIfNegative();
		void JmpIfNotNegative();
		void JmpIfOverflow();
		void JmpIfNotOverflow();
		void JmpIfCarry();
		void JmpIfNotCarry();

		void JmpIfSignedLessThan();
		void Nop();
	};
}

#endif // ALVM_RUNTIME_H